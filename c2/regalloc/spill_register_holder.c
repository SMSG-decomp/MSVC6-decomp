void __fastcall spill_register_holder(uint32_t regno,c2_tuple *t,c2_tuple *t2,c2_operand *src)

{
  c2_operand *pcVar1;
  c2_operand_u18 cVar2;
  c2_operand *dst;
  c2_tuple *pcVar3;
  c2_symbol *pcVar4;
  int only_live;
  ushort type;
  
  pcVar1 = src->sym->def->dst;
  while ((pcVar1 != (c2_operand *)0x0 &&
         (((pcVar1->kind != '\x01' || (((pcVar1->u18).reg)->cls != '\x01')) ||
          (((pcVar1->u18).reg)->storage->id != regno))))) {
    pcVar1 = pcVar1->next;
  }
  type = src->type;
  if ((src->type & 0xfff) < (pcVar1->type & 0xfff)) {
    type = pcVar1->type;
  }
  dst = operand_new_temp_sym(type);
  pcVar3 = tuple_new(1,type,dst,src,tuple_insert_before,t);
  pcVar1 = pcVar3->src;
  pcVar4 = reg_find_subreg(g_reg_symbols + regno,(pcVar1->type & 0xfff) << 3,0);
  (pcVar1->u18).reg = pcVar4;
  pcVar1->flags11 = pcVar1->flags11 | 0x10;
  pcVar3 = tuple_new_unary_temp(1,type,dst,tuple_insert_before,t2);
  pcVar1 = pcVar3->dst;
  pcVar1->u18 = *(c2_operand_u18 *)(g_register_holders + regno);
  pcVar3->line = t2->line;
  cVar2 = (c2_operand_u18)pcVar1->sym;
  src->sym = (c2_symbol *)cVar2;
  pcVar1->u18 = cVar2;
  if ((g_opt_global == 0) || (g_no_global_candidates != 0)) {
    only_live = 0;
  }
  else {
    only_live = 1;
  }
  local_ra_rename_register_in_span(t,(src->u18).reg,t2,pcVar1->sym,only_live);
  return;
}

