int __fastcall sizeopt_has_byte_def_at_least(void *rec,uint32_t n)

{
  int iVar1;
  
  iVar1 = *(int *)((int)rec + 8);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(int *)(iVar1 + 0x20) == 4) && (n <= *(byte *)(iVar1 + 0x30))) break;
    iVar1 = *(int *)(iVar1 + 0xc);
  }
  return 1;
}

