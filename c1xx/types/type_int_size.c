int __cdecl type_int_size(void)

{
  char cVar1;
  c1_type *pcVar2;
  
  pcVar2 = type_int();
  cVar1 = (char)pcVar2->code;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  return (int)(char)(&g_type_rank_table)[(byte)pcVar2->code & 0xf];
}

