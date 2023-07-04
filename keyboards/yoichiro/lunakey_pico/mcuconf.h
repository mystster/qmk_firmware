// Copyright 2022 Yoichiro Tanaka (@yoichiro)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>
#undef STM32_SIO_USE_USART0
#define STM32_SIO_USE_USART0 TRUE
#undef RP_PWM_USE_PWM4
#define RP_PWM_USE_PWM4 TRUE
