c2_node * __fastcall build_nary_expression_tree(c2_tuple *t)

{
  uint16_t type;
  uint32_t uVar1;
  c2_operand *src;
  c2_tuple *conv_tuple;
  c2_operand *new_op;
  int iVar2;
  c2_operand *use_opnd;
  c2_tuple *def_tuple;
  bool negate_next;
  c2_operand *next_opnd;
  
  use_opnd = t->src;
  negate_next = false;
  t->src = (c2_operand *)0x0;
  if (use_opnd == (c2_operand *)0x0) {
    return (c2_node *)t;
  }
  do {
    next_opnd = use_opnd->next;
    use_opnd->next = (c2_operand *)0x0;
    use_opnd->flags = use_opnd->flags & 0xef;
    new_op = use_opnd;
    if (((((1 << (use_opnd->kind & 0x1f) & 6U) != 0) &&
         (def_tuple = use_opnd->sym->def, def_tuple != (c2_tuple *)0x0)) &&
        (def_tuple->flags12 == '\x02')) &&
       ((uVar1 = decide_tree_substitution(def_tuple,use_opnd), uVar1 == 0 &&
        (new_op = (c2_operand *)build_nary_expression_tree(def_tuple), new_op != use_opnd)))) {
      conv_tuple = (c2_tuple *)new_op;
      if (t->op == 0x15f) {
LAB_10707bf4:
        if (use_opnd->type != new_op->type) {
LAB_10707bfe:
          if (new_op->op != 0x17d) {
            type = use_opnd->type;
            src = operand_new_temp(type);
            conv_tuple = tuple_new_unary_temp(0x15f,type,src,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
            tuple_replace_src(conv_tuple,conv_tuple->src,new_op);
            conv_tuple->flags12 = '\x02';
          }
        }
      }
      else {
        if (t->type != new_op->type) goto LAB_10707bfe;
        if (t->op == 0x15f) goto LAB_10707bf4;
      }
      new_op = (c2_operand *)conv_tuple;
      if ((c2_operand *)conv_tuple != use_opnd) {
        node_free((c2_node *)use_opnd);
      }
    }
    if (t->op == 0x16d) {
      if (negate_next) {
        new_op = (c2_operand *)negate_operand((c2_node *)new_op,(c2_tuple *)0x0);
        negate_next = false;
      }
    }
    else if ((t->op == 0x16e) && ((t->type & 0xf000) != 0x4000)) {
      t->op = 0x16d;
      negate_next = true;
    }
    if ((t->op == new_op->op) && (iVar2 = tuple_is_commutative((c2_tuple *)new_op), iVar2 != 0)) {
      append_operand_list(t,(c2_tuple *)new_op);
      node_free((c2_node *)new_op);
    }
    else {
      tuple_append_src(t,new_op);
    }
    use_opnd = next_opnd;
    if (next_opnd == (c2_operand *)0x0) {
      return (c2_node *)t;
    }
  } while( true );
}

