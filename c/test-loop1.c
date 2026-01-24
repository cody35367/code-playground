#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define TRACK_MSG_MIN_SIZE 35
#define TRACK_MSG_MAX_SIZE 38
#define MAX_STR_LEN 100

typedef int32_t int32;
typedef uint8_t uint8;

static int32 calcMsgSize(char * buffer, int32 endOffset) {
    int32 msgSize = 0;
    int32 startOffset = endOffset;

    if (endOffset + 1 >= TRACK_MSG_MIN_SIZE) {
        for (int i = endOffset; i >= 0; i--) {
            if ('\n' == buffer[i]) {
                break;
            }
            startOffset--;
        }
        msgSize = endOffset - startOffset;
    }
    return msgSize;
}

static int32 calcEndIndex(char * buffer, int32 size) {
    int32 currentIndex = size - 1;
    while (currentIndex > 0) {
        if (buffer[currentIndex] == '\n') {
            currentIndex--;
            if (buffer[currentIndex] == '\r') {
                currentIndex--;
                break;
            }
        }
        currentIndex--;
    }
    return currentIndex;
}

int main() {
    char testStrs[][MAX_STR_LEN] = {                            /*Idx, Len*/
        "0---.- --- ----.- --- ----.- --- FF\r\n",              /* 34, 35 */
        "\n1---.- --- ----.- --- ----.- --- FF\r\n",            /* 35, 35 */
        "20000.0 --- ----.- --- ----.- --- FF\r\n",             /* 35, 36 */
        "30000.0 --- 20000.0 --- ----.- --- FF\r\n",            /* 36, 37 */
        "40000.0 --- 20000.0 --- 20000.0 --- FF\r\n",           /* 37, 38 */
        "FF\r\n50000.0 --- 20000.0 --- 20000.0 --- FF\r\n",     /* 41, 38 */
    };
    char trackMsg[TRACK_MSG_MAX_SIZE + 1] = {0};
    int32 endIdx = 0;
    int32 msgSize = 0;
    for (int i = 0; i < (int)(sizeof(testStrs)/MAX_STR_LEN); i++) {
        endIdx = calcEndIndex(testStrs[i], strlen(testStrs[i]));
        msgSize = calcMsgSize(testStrs[i], endIdx);
        memcpy(trackMsg, (uint8*)&testStrs[i] + ((endIdx - msgSize) + 1), msgSize);
        trackMsg[msgSize] = '\0';
        printf("%d: %d %d %s\n",
            i,
            endIdx,
            msgSize,
            trackMsg
        );
    }
}