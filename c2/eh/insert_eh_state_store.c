c2_tuple * __fastcall
insert_eh_state_store(int32_t new_state,int32_t old_state,c2_eh_state *object,c2_tuple *pos)

{
  c2_symbol *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *t;
  c2_const_operand *op;
  c2_eh_op_construct *pcVar3;
  c2_eh_state *pcVar4;
  uint16_t type;
  int hi;
  
  if (((old_state == -2) ||
      (((old_state == 0 && (g_eh_return_object_record != (c2_eh_state *)0x0)) ||
       (((new_state ^ old_state) & 0xffffff00U) != 0)))) ||
     (pcVar4 = eh_state_lookup(old_state), (pcVar4->flags & 0x100) != 0)) {
    pcVar1 = symbol_get_part(g_cxx_eh_record,0x1004,0,g_cxx_eh_next_offset + 8);
    pcVar2 = operand_new_sym(0x14a,0x1004,pcVar1);
    t = tuple_new_pseudo(0x1a8,0x1004);
    tuple_append_dst(t,pcVar2);
    type = 0x1004;
    hi = new_state >> 0x1f;
  }
  else {
    pcVar1 = symbol_get_part(g_cxx_eh_record,0x2001,0,g_cxx_eh_next_offset + 8);
    pcVar2 = operand_new_sym(0x14a,0x2001,pcVar1);
    t = tuple_new_pseudo(0x1a8,0x2001);
    tuple_append_dst(t,pcVar2);
    type = 0x2001;
    new_state = new_state & 0xff;
    hi = 0;
  }
  op = operand_new_intconst(type,new_state,hi);
  tuple_append_src(t,op);
  tuple_insert_after(pos,t);
  pcVar3 = arena_alloc(1,0x10);
  (t->u20).eh_construct = pcVar3;
  pcVar3->object = object;
  return t;
}

