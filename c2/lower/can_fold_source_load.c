uint32_t __fastcall can_fold_source_load(c2_tuple *t,c2_operand *opnd)

{
  c2_operand *pcVar1;
  
  if ((((t->kind != '\x13') && (t->kind != '\x14')) && (t->op != 0x166)) &&
     ((((opnd->flags & 0x20) == 0 && ((1 << (opnd->kind & 0x1f) & 6U) != 0)) &&
      (opnd->sym->def != (c2_tuple *)0x0)))) {
    pcVar1 = find_dst_clobbering_reg(t,(opnd->u18).reg);
    if (pcVar1 == (c2_operand *)0x0) {
      return 1;
    }
  }
  return 0;
}

