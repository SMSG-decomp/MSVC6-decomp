int __fastcall find_in_table6(uint32_t op,uint32_t *table)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*table == op) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    table = table + 1;
  } while (iVar1 < 6);
  return -1;
}

