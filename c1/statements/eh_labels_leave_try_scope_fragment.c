void __cdecl eh_labels_leave_try_scope_fragment(c1_symbol *label,c1_u8 mark)

{
  byte bVar1;
  c1_sym_link *link;
  
  while ((link = label->next, link != (c1_sym_link *)0x0 &&
         (label = (c1_symbol *)&link[-1].position, label != (c1_symbol *)0x0))) {
    bVar1 = *(byte *)((int)&link[2].name + 1);
    if (g_seh_finally_depth + g_seh_except_depth + g_seh_try_depth <= (int)(uint)bVar1) {
      if ((link[-1].position & 0x100) == 0) {
        *(byte *)((int)&link[2].name + 1) = bVar1 - 1;
      }
      else {
        *(byte *)&link[-1].type = *(byte *)&link[-1].type | mark;
      }
    }
  }
  return;
}

