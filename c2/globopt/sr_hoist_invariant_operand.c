void __fastcall sr_hoist_invariant_operand(c2_operand *op,c2_loop *loop)

{
  uint16_t type;
  int iVar1;
  c2_operand *src;
  
  iVar1 = range_may_alias(loop->preheader->head,&loop->preheader->end->next,op);
  if (iVar1 == 0) {
    type = op->type;
    src = materialize_value_in_preheader(type,op,g_preheader_insert_point,0);
    tuple_new(0x15b,type,op,src,tuple_insert_before,g_preheader_insert_point);
  }
  return;
}

