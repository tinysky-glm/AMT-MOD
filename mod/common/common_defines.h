/*!
 * \file common_defines.h
 * \brief The common defines.
 */
#pragma once

#include <stdint.h>

/*
 * #pragma once是一个比较常用的C/C++标注，
 * 只要在头文件的最开始加入这条杂注，就能够保证头文件只被编译一次
 */

namespace mod {
/*
 * 表示命名空间——其中可以声明若干标识符，变量名与其它命名空间不冲突
 */

typedef int32_t mod_int_t;
/*
 * 定义用于描述mod系统中整形的类型, 譬如: 点的个数
 */

typedef float mod_float_t;
/*
 * 定义用于描述mod系统中浮点型的类型, 譬如: 经纬度
 */

}  // namespace mod


