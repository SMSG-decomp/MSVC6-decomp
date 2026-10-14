c2_tuple * __fastcall
materialize_iv_in_preheader
          (c2_operand *op,uint16_t type,c2_operand *step,uint32_t update_op,c2_symbol *biv,
          int queue_copy,c2_loop *loop,c2_function *fn)

{
  c2_symbol *sym;
  c2_tuple *pcVar1;
  c2_operand *src;
  c2_tuple *t;
  c2_tuple *local_8;
  
  sym = op->sym;
  local_8 = (c2_tuple *)0x0;
  pcVar1 = tuple_new_block_boundary();
  tuple_insert_before(g_preheader_insert_point,pcVar1);
  src = materialize_value_in_preheader(type,op,g_preheader_insert_point,0);
  tuple_new(0x15b,type,op,src,tuple_insert_before,g_preheader_insert_point);
  t = tuple_new_block_boundary();
  tuple_insert_before(g_preheader_insert_point,t);
  cse_replace_in_range(pcVar1,&t->next,loop,fn);
  if (queue_copy != 0) {
    local_8 = t->prev;
    iv_worklist_push(local_8);
    op = local_8->dst;
  }
  tuple_unlink(pcVar1);
  node_free((c2_node *)pcVar1);
  tuple_unlink(t);
  node_free((c2_node *)t);
  pcVar1 = tuple_new_binary_temp(update_op,type,op,step,tuple_insert_after,(biv->defs->u04).tuple);
  pcVar1->flags13 = '\x04';
  add_symbol_loop_use(sym,pcVar1);
  pcVar1 = tuple_new(0x15b,type,op,pcVar1->dst,tuple_insert_after,pcVar1);
  pcVar1->flags13 = '\x04';
  add_symbol_loop_def(sym,pcVar1);
  return local_8;
}

