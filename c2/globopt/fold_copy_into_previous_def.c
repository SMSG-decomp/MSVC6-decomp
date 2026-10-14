uint32_t __fastcall fold_copy_into_previous_def(c2_tuple *t)

{
  uint16_t type;
  c2_symbol *chain;
  c2_tuple *t_00;
  c2_tuple *pcVar1;
  int iVar2;
  c2_operand *pcVar3;
  c2_operand *local_8;
  c2_operand *local_4;
  
  pcVar3 = t->dst;
  local_4 = t->src;
  if ((((1 << (pcVar3->kind & 0x1f) & 6U) != 0) && (pcVar3->sym->def != (c2_tuple *)0x0)) &&
     ((g_opt_dlp == 0 || (local_4->kind != '\x05')))) {
    t_00 = find_next_use_of_dst(t,&local_8);
    pcVar1 = tuple_next_real_before_boundary(t);
    if ((((((t_00 == pcVar1) && (iVar2 = types_compatible(t->type,local_8->type), iVar2 != 0)) &&
          (t_00->op != 0x19e)) &&
         ((chain = local_8->sym, chain == (local_8->u18).reg && (pcVar3->sym == chain)))) &&
        (chain->storage == chain)) && (((local_8->flags & 0x20) == 0 || (local_4->kind == '\x01'))))
    {
      type = local_8->type;
      pcVar3 = tuple_replace_src(t_00,local_8,local_4);
      if (pcVar3->type != type) {
        operand_set_type(pcVar3,type);
      }
      tuple_delete(t);
      symbol_free_chain(chain);
      return 1;
    }
  }
  return 0;
}

