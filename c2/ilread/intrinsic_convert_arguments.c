void __fastcall intrinsic_convert_arguments(c2_tuple *type)

{
  uint16_t type_00;
  c2_tuple *t;
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  c2_operand *pcVar3;
  uint16_t *puVar4;
  uint id;
  int local_14;
  c2_operand *local_10;
  uint local_c;
  c2_tuple *local_8;
  c2_operand *local_4;
  
  id = (uint)(type->u20).intrinsic.id;
  local_c = id;
  puVar4 = intrinsic_param_types(id);
  local_14 = 0;
  pcVar3 = type->src;
  do {
    if (pcVar3 == (c2_operand *)0x0) {
      return;
    }
    local_4 = pcVar3->next;
    if (4 < local_14) {
      if ((g_intrinsic_desc[id].flags & 0x10) != 0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\misc.c",0x254);
      }
      puVar4 = puVar4 + -1;
    }
    t = pcVar3->sym->def;
    local_10 = t->src;
    type_00 = *puVar4;
    if ((type_00 != 0) && (type_00 != local_10->type)) {
      local_8 = t->prev;
      tuple_detach_src((c2_node *)t,local_10);
      convert_operand(&local_10,type_00,&local_8);
      tuple_append_src(t,local_10);
      pcVar1 = t->dst;
      pcVar2 = pcVar3->sym;
      t->type = type_00;
      pcVar3->type = type_00;
      pcVar1->type = type_00;
      pcVar2->type = type_00;
    }
    local_14 = local_14 + 1;
    puVar4 = puVar4 + 1;
    pcVar3 = local_4;
    id = local_c;
  } while( true );
}

