c2_tuple * __fastcall lower_int64_mul_div_shift_call(c2_tuple *anchor)

{
  uint32_t uVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_fe_symbol *fs;
  c2_operand *pcVar4;
  c2_tuple *t;
  uint uVar5;
  c2_symbol *pcVar6;
  c2_int64_helper *row;
  int iVar7;
  c2_int64_helper *table;
  int iVar8;
  c2_int64_helper *helpers;
  c2_int64_helper *next_row;
  
  if (((anchor->op == 0x16f) && ((anchor->src->type & 0xfff) == 4)) &&
     ((anchor->src->next->type & 0xfff) == 4)) {
    anchor->op = (-(uint)((anchor->type & 0xf000) != 0x1000) & 0x1c) + 6;
    return anchor;
  }
  if ((anchor->type & 0xf000) == 0x2000) {
    table = g_int64_unsigned_helpers;
    helpers = g_int64_unsigned_helpers;
  }
  else {
    helpers = g_int64_signed_helpers;
    table = g_int64_signed_helpers;
  }
  iVar8 = 0;
  uVar1 = table->op;
  row = table;
  while ((uVar1 != 0x145 && (uVar1 != anchor->op))) {
    next_row = row + 1;
    row = row + 1;
    iVar8 = iVar8 + 1;
    uVar1 = next_row->op;
  }
  if (table[iVar8].op != 0x145) {
    fs = fe_symbol_lookup_name(table[iVar8].name);
    pcVar4 = operand_for_symbol_ref(fs);
    wrap_first_args_in_arg_copies(anchor,2);
    t = tuple_make_helper_call_2(anchor,0xe,pcVar4,'\x10');
    if (table[iVar8].argregs[0] != 0) {
      iVar7 = 0;
      for (pcVar4 = t->src->next; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
        if (((1 << (pcVar4->kind & 0x1f) & 6U) != 0) &&
           (pcVar2 = pcVar4->sym->def, pcVar2 != (c2_tuple *)0x0)) {
          if ((pcVar4->type & 0xfff) < 4) {
            uVar5 = pcVar4->type & 0xfff;
          }
          else {
            uVar5 = 4;
          }
          pcVar6 = reg_find_subreg(g_reg_symbols + helpers[iVar8].argregs[iVar7],uVar5 * 8,0);
          pcVar3 = pcVar2->dst;
          (pcVar4->u18).reg = pcVar6;
          (pcVar3->u18).reg = pcVar6;
        }
        iVar7 = iVar7 + 1;
      }
    }
    lower_pending_arg_copies(t);
    return t;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lower.c",0xb1d);
}

