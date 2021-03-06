#include <FreeRTOS.h>
#include <task.h>

//------------------------------------------------------------------------------
/** vAssertBlink
 * Blink one short pulse every two seconds if configASSERT fails.
 */
void __attribute__((weak)) vBlink(const int n)
{
    (void)(n);

    while (1) {
        __asm volatile("nop");
    }
}

//------------------------------------------------------------------------------
/** vAssertBlink
 * Blink one short pulse every two seconds if configASSERT fails.
 */
void __attribute__((weak)) vAssertBlink()
{
    vBlink(1);
}

//------------------------------------------------------------------------------
/** This function will be called by each tick interrupt if
  configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
  added here, but the tick hook is called from an interrupt context, so
  code must not attempt to block, and only the interrupt safe FreeRTOS API
  functions can be used (those that end in FromISR()). */
void __attribute__((weak)) vApplicationTickHook() { }

//------------------------------------------------------------------------------
/** vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
  to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
  task.  It is essential that code added to this hook function never attempts
  to block in any way (for example, call xQueueReceive() with a block time
  specified, or call vTaskDelay()).  If the application makes use of the
  vTaskDelete() API function (as this demo application does) then it is also
  important that vApplicationIdleHook() is permitted to return to its calling
  function, because it is the responsibility of the idle task to clean up
  memory allocated by the kernel to any task that has since been deleted. */
void __attribute__((weak)) vApplicationIdleHook(void) { }

//------------------------------------------------------------------------------
/** vApplicationMallocFailedHook()
   Blink two short pulses if malloc fails.

  will only be called if
  configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
  function that will get called if a call to pvPortMalloc() fails.
  pvPortMalloc() is called internally by the kernel whenever a task, queue,
  timer or semaphore is created.  It is also called by various parts of the
  demo application.  If heap_1.c or heap_2.c are used, then the size of the
  heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
  FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
  to query the size of free heap space that remains (although it does not
  provide information on how the remaining heap might be fragmented). */
void __attribute__((weak)) vApplicationMallocFailedHook()
{
    vBlink(2);
}

/*-----------------------------------------------------------*/
/**  Blink three short pulses if stack overflow is detected.
  Run time stack overflow checking is performed if
  configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
  function is called if a stack overflow is detected.
  \param[in] pxTask Task handle
  \param[in] pcTaskName Task name
  */
void __attribute__((weak))
vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)pxTask;
    vBlink(3);
}

//------------------------------------------------------------------------------
/** Hard fault - blink four short flash every two seconds */
void HardFault_Handler()
{
    vBlink(4);
}
/** Bus fault - blink five short flashes every two seconds */
void BusFault_Handler()
{
    vBlink(5);
}
/** Usage fault - blink six short flashes every two seconds */
void UsageFault_Handler()
{
    vBlink(6);
}
