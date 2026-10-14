int __fastcall tuple_label_may_follow(c2_tuple *t)

{
  uint8_t uVar1;
  
  uVar1 = t->kind;
  if ((((uVar1 != '\x11') || ((t->u20).cond_cells != (c2_cond_cell *)0x0)) || (t->op == 0x18b)) &&
     ((uVar1 != '\x13' && ((g_jumpopt_no_crossjump != 0 || (uVar1 != '\x0f')))))) {
    return 1;
  }
  return 0;
}

