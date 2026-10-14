int __fastcall x87_depth_of_value(int id)

{
  int iVar1;
  uint32_t *puVar2;
  
  iVar1 = 0;
  if (-1 < g_x87_tos) {
    puVar2 = g_x87_stack_ids + g_x87_tos;
    do {
      if (*puVar2 == id) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + -1;
    } while (iVar1 <= g_x87_tos);
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x19b);
}

