uint32_t compute_alias_points_to_case_a3
                   (c2_tuple *t,c2_alias_scope_slot *scope_stack,int scope_depth,c2_bitset *reaching
                   ,c2_block *block,uint32_t next_scope_cls,uint32_t list_pass,
                   c2_tuple *last_eh_call,c2_tuple *cursor,int oa,int oa_across_calls)

{
  c2_operand *op;
  uint32_t uVar1;
  
  op = memory_effect_for_call_arg(t->src,reaching,scope_stack[scope_depth].cls,(int)block);
  tuple_append_src(t,op);
  uVar1 = compute_alias_points_to_case_ad
                    (t,scope_stack,scope_depth,reaching,block,next_scope_cls,list_pass,last_eh_call,
                     cursor,oa,oa_across_calls);
  return uVar1;
}

