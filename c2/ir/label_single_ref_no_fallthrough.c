int __fastcall label_single_ref_no_fallthrough(c2_tuple *label)

{
  c2_tuple *pcVar1;
  
  if (*(int *)&label->src[1].type == 1) {
    pcVar1 = tuple_prev_real_in_block(label);
    if (pcVar1 != (c2_tuple *)0x0) {
      if (pcVar1->kind == '\x0f') {
        return 1;
      }
      if ((((pcVar1->kind == '\x11') && ((pcVar1->u20).cond_cells == (c2_cond_cell *)0x0)) &&
          (pcVar1->op != 0x18b)) &&
         (((pcVar1->src->kind != '\x04' ||
           (pcVar1 = *(c2_tuple **)((int)&pcVar1->src->sym->u30 + 2), pcVar1 == (c2_tuple *)0x0)) ||
          (pcVar1 != label)))) {
        return 1;
      }
    }
  }
  return 0;
}

