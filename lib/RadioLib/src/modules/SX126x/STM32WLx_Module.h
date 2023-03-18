/*

Copyright (c) 2022 STMicroelectronics

This file is licensed under the MIT License: https://opensource.org/licenses/MIT
*/

#if !defined(_RADIOLIB_STM32WLX_MODULE_H)
#define _RADIOLIB_STM32WLX_MODULE_H

#include "../../TypeDef.h"

#if !defined(RADIOLIB_EXCLUDE_STM32WLX)

#include "../../Module.h"

/*!
 * \class STM32WLx_Module
 *
 * This is a subclass of Module to be used with the STM32WLx driver.
 *
 * It is used to override some callbacks, allowing access to some of the
 * radio control signals that are wired to internal registers instead of
 * actual GPIO pins.
 */
class STM32WLx_Module : public Module {
  // Note: We cannot easily override any methods here, since most calls
  // are non-virtual and made through a Module*, so they would not be
  // calling any overridden methods. This means this class works by
  // overriding some of the callbacks in its constructor.

  public:
    STM32WLx_Module();

#if !defined(RADIOLIB_GODMODE)
  private:
#endif

    // Replacement callbacks to handle virtual pins. These are static,
    // since they replace global functions that cannot take any this
    // pointer for context.
    static void virtualPinMode(uint32_t dwPin, uint32_t dwMode);
    static void virtualDigitalWrite(uint32_t dwPin, uint32_t dwVal);
    static int virtualDigitalRead(uint32_t ulPin);
};

#endif // !defined(RADIOLIB_EXCLUDE_STM32WLX)

#endif // _RADIOLIB_STM32WLX_MODULE_H
