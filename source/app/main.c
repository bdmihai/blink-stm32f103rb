/*_____________________________________________________________________________
 │                                                                            |
 │ COPYRIGHT (C) 2020 Mihai Baneu                                             |
 │                                                                            |
 | Permission is hereby  granted,  free of charge,  to any person obtaining a |
 | copy of this software and associated documentation files (the "Software"), |
 | to deal in the Software without restriction,  including without limitation |
 | the rights to  use, copy, modify, merge, publish, distribute,  sublicense, |
 | and/or sell copies  of  the Software, and to permit  persons to  whom  the |
 | Software is furnished to do so, subject to the following conditions:       |
 |                                                                            |
 | The above  copyright notice  and this permission notice  shall be included |
 | in all copies or substantial portions of the Software.                     |
 |                                                                            |
 | THE SOFTWARE IS PROVIDED  "AS IS",  WITHOUT WARRANTY OF ANY KIND,  EXPRESS |
 | OR   IMPLIED,   INCLUDING   BUT   NOT   LIMITED   TO   THE  WARRANTIES  OF |
 | MERCHANTABILITY,  FITNESS FOR  A  PARTICULAR  PURPOSE AND NONINFRINGEMENT. |
 | IN NO  EVENT SHALL  THE AUTHORS  OR  COPYRIGHT  HOLDERS  BE LIABLE FOR ANY |
 | CLAIM, DAMAGES OR OTHER LIABILITY,  WHETHER IN AN ACTION OF CONTRACT, TORT |
 | OR OTHERWISE, ARISING FROM,  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  |
 | THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                 |
 |____________________________________________________________________________|
 |                                                                            |
 |  Author: Mihai Baneu                           Last modified: 15.May.2020  |
 |                                                                            |
 |___________________________________________________________________________*/

#include "stm32f1xx.h"
#include "stm32rtos.h"
#include "task.h"
#include "system.h"
#include "gpio.h"
#include "isr.h"
#include "utils.h"

static void vTaskLED(void *pvParameters)
{
    (void)pvParameters;

    /* led OFF */
    GPIOC->BSRR = GPIO_BSRR_BS13;

    for (;;) {
        GPIOC->BSRR = GPIO_BSRR_BS13;
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        GPIOC->BSRR = GPIO_BSRR_BR13;
        vTaskDelay(100 / portTICK_PERIOD_MS);

         GPIOC->BSRR = GPIO_BSRR_BS13;
        vTaskDelay(100 / portTICK_PERIOD_MS);

        GPIOC->BSRR = GPIO_BSRR_BR13;
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

int main(void)
{
    /* initialize the system */
    vSystemInit();

    /* initialize the gpio */
    vGPIOInit();

    /* initialize the interupt service routines */
    vISRInit();

    /* create the tasks specific to this application. */
    xTaskCreate(vTaskLED, (const portCHAR *)"vTaskLED", configMINIMAL_STACK_SIZE, NULL, 2, NULL);

    /* start the scheduler. */
    vTaskStartScheduler();

    /* should never go here ... */
    vBlink(10);
    return 0;
}
