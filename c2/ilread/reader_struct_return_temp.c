c2_operand * __fastcall reader_struct_return_temp(c2_function *fn,c2_tuple *call,int size)

{
  c2_fe_symbol *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *index;
  uint32_t alias_tag;
  
  pcVar1 = fe_symbol_new_local(fn->scope,6,size,1,1,'\x04',0);
  pcVar2 = operand_for_symbol_ref(pcVar1);
  pcVar1 = pcVar2->sym->fe;
  pcVar1->storage = pcVar1->storage | 0x40000;
  pcVar3 = tuple_new_unary_temp(0x15a,0x3004,pcVar2,tuple_splice_after,call->prev);
  pcVar2 = (c2_operand *)node_clone((c2_node *)pcVar3->dst);
  tuple_insert_src_after(call,call->src,pcVar2);
  pcVar2 = call->dst;
  alias_tag = 0;
  index = (c2_operand *)0x0;
  pcVar2->type = 0x3004;
  pcVar2 = (c2_operand *)node_clone((c2_node *)pcVar2);
  pcVar2 = operand_new_mem(0x14c,(0xfff < size) - 1 & (ushort)size | 0x5000,(c2_symbol *)0x0,0,
                           pcVar2,index,alias_tag);
  tuple_splice_after(call,(c2_tuple *)pcVar2);
  return pcVar2;
}

