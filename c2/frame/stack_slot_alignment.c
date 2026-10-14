uint32_t __fastcall stack_slot_alignment(c2_bitset *bs,c2_function *fn)

{
  int iVar1;
  
  if ((fn->flags & 0x600000) != 0) {
    iVar1 = bitset_iter_next(bs);
    while (iVar1 != -1) {
      if (((g_stack_object_table[iVar1]->type & 0xf000) == 0x4000) &&
         (g_stack_object_table[iVar1]->type == 0x4008)) {
        return 8;
      }
      iVar1 = bitset_iter_next((c2_bitset *)0x0);
    }
  }
  return 0;
}

