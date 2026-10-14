void __fastcall rewrite_as_rmw_tuple(c2_tuple *anchor,c2_operand *src1,c2_operand *src2,c2_tuple *t)

{
  c2_symbol *pcVar1;
  c2_tuple *t2;
  
  if (((anchor->src->kind != '\x01') || (pcVar1 = anchor->src->sym, pcVar1->cls != '\x03')) ||
     (pcVar1->def == (c2_tuple *)0x0)) {
    tuple_new(0x15b,t->type,t->dst,anchor->dst,tuple_insert_after,anchor);
  }
  t2 = tuple_new_binary(t->op,anchor->type,anchor->dst,src1,src2,(c2_insert_fn *)0x0,(c2_tuple *)0x0
                       );
  tuple_replace(anchor,(c2_node *)t2);
  tuple_unlink_free(t);
  return;
}

