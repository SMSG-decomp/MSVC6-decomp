uint32_t __fastcall basic_number_op18b_sites(c2_function *fn)

{
  c2_tuple *pcVar1;
  uint uVar2;
  
  uVar2 = (uint)(g_seh_try_end_label == (c2_tuple *)0x0);
  for (pcVar1 = fn->cfg->first->head; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
    if (pcVar1->op == 0x18b) {
      pcVar1->flags12 = (char)(short)uVar2;
      pcVar1->flags13 = (char)((ushort)(short)uVar2 >> 8);
      uVar2 = uVar2 + 1;
    }
  }
  return uVar2;
}

