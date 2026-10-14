c2_tuple * __fastcall tuple_new_jmp_before(c2_tuple *label,c2_tuple *anchor)

{
  c2_tuple *pcVar1;
  
  pcVar1 = tuple_new_branch(0x10,'\0',(c2_node *)label,(c2_operand *)0x0,(c2_tuple *)0x0,
                            tuple_insert_before,anchor);
  return pcVar1;
}

