uint32_t val;
unsigned char buf[4];

val = 0;
for (int i = 0 ; i < 16; i++)
{
    val += (1<<i); // 16 set bits
}

memset(buf+0, *( ((unsigned char*)&val) + (unsigned char)0 ), 1 );
memset(buf+1, *( ((unsigned char*)&val) + (unsigned char)1 ), 1 );
memset(buf+2, *( ((unsigned char*)&val) + (unsigned char)2 ), 1 );
memset(buf+3, *( ((unsigned char*)&val) + (unsigned char)3 ), 1 );

/*
* Only 16 bits out of 32 bits of val have ben set. Were're moving
* the poninters by one byte (8 bits), so it prints 255 (8 set bits) twice
* and then 0 twice.
*/
printf("%d\n", (int)buf[0]);
printf("%d\n", (int)buf[1]);
printf("%d\n", (int)buf[2]);
printf("%d\n", (int)buf[3]);