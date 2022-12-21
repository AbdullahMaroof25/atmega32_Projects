

#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed int s64;


typedef float f32;

typedef enum{FALSE=0,TRUE}Bool_t;

#define NULLPTR   ((void*)0)

typedef enum
{
	Enable=0,
	Disable
}Interrupt_statue;

#endif /* STDTYPES_H_ */