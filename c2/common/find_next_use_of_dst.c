c2_tuple * __fastcall find_next_use_of_dst(c2_tuple *t,c2_operand **use)

{
  c2_tuple *pcVar1;
  
  pcVar1 = find_next_use_of_symbol((c2_node *)t,t->dst->sym,use);
  return pcVar1;
}

