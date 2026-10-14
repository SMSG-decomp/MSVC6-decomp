c2_tuple * __fastcall build_helper_call(c2_node *t,uint32_t op,c2_operand *fn,uint8_t flag)

{
  c2_tuple *call;
  
  call = tuple_make_helper_call((c2_tuple *)t,op,fn,flag);
  add_call_clobber_set(call);
  return call;
}

