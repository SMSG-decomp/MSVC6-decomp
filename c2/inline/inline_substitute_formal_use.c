c2_tuple * __fastcall inline_substitute_formal_use(c2_tuple *t,c2_operand *actual)

{
  uint8_t uVar1;
  ushort type;
  c2_tuple *use_t;
  c2_symbol *pcVar2;
  c2_operand *pcVar3;
  c2_replace_fn *replace_fn;
  uint32_t op;
  c2_operand *use_opnd;
  c2_operand *found_list;
  c2_tuple *def_t;
  
  use_t = find_next_use_of_dst(t,&use_opnd);
  uVar1 = actual->kind;
  switch(uVar1) {
  case '\x01':
  case '\x02':
    type = use_opnd->type;
    if (actual->type == type) {
      use_opnd = tuple_replace_src(use_t,use_opnd,actual);
    }
    else {
      pcVar2 = symbol_get_part(actual->sym,type,type & 0xfff,0);
      if (uVar1 == '\x02') {
        pcVar3 = operand_new_sym(actual->op,use_opnd->type,pcVar2);
      }
      else {
        pcVar3 = operand_new_reg(0x149,use_opnd->type,pcVar2,pcVar2->storage);
      }
      use_opnd = tuple_replace_src(use_t,use_opnd,pcVar3);
      node_free((c2_node *)actual);
    }
    if (((1 << (use_opnd->kind & 0x1f) & 6U) != 0) &&
       (def_t = use_opnd->sym->def, def_t != (c2_tuple *)0x0)) {
      tuple_unlink(def_t);
      def_t->flags12 = def_t->flags12 + use_t->flags12;
      tuple_insert_before(use_t,def_t);
      hoist_defining_tuples(def_t,use_t->flags12);
    }
    return use_t;
  case '\x03':
    if ((use_opnd->flags & 0x20) != 0) {
      use_opnd = find_mem_operand_using(use_t,use_opnd,&found_list);
      uVar1 = actual->sym->cls;
      if ((((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) ||
         (op = 0x14b, uVar1 == '\x06')) {
        op = 0x14a;
      }
      replace_fn = tuple_replace_dst;
      if (found_list != use_t->dst) {
        replace_fn = tuple_replace_src;
      }
      pcVar2 = symbol_get_part(actual->sym,use_opnd->type,use_opnd->type & 0xfff,0);
      pcVar3 = operand_new_sym(op,use_opnd->type,pcVar2);
      (*replace_fn)(use_t,use_opnd,pcVar3);
      node_free((c2_node *)actual);
      return use_t;
    }
    break;
  case '\x04':
    tuple_replace_src(use_t,use_opnd,actual);
    return use_t;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\inline.c",0x78d);
  case '\a':
    if (actual->type != use_opnd->type) {
      pcVar3 = operand_new_intconst(use_opnd->type,(actual->u18).lo,actual->tag);
LAB_10794508:
      tuple_replace_src(use_t,use_opnd,pcVar3);
      node_free((c2_node *)actual);
      return use_t;
    }
    break;
  case '\t':
    if (actual->type != use_opnd->type) {
      pcVar3 = operand_new_fconst(use_opnd->type,(c2_float_const *)actual->sym);
      goto LAB_10794508;
    }
  }
  tuple_replace_src(use_t,use_opnd,actual);
  return use_t;
}

