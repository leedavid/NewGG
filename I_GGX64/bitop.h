#ifndef __BITOP_H__
#define __BITOP_H__

#ifdef _MSC_VER
#else
    static __inline unsigned char _BitScanForward64(unsigned long* Index, unsigned long long Mask)
    {
        unsigned long long Ret;
        __asm__
        (
            "bsfq %[Mask], %[Ret]"
            :[Ret] "=r" (Ret)
            :[Mask] "mr" (Mask)
        );
        *Index = (unsigned long)Ret;
        return Mask?1:0;
    }
    static __inline unsigned char _BitScanReverse64(unsigned long* Index, unsigned long long Mask)
    {
        unsigned long long Ret;
        __asm__
        (
            "bsrq %[Mask], %[Ret]"
            :[Ret] "=r" (Ret)
            :[Mask] "mr" (Mask)
        );
        *Index = (unsigned long)Ret;
        return Mask?1:0;
    }
#endif

#endif