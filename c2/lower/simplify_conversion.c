c2_node * __fastcall simplify_conversion(c2_tuple *t,c2_tuple *user)

{
  ushort type;
  c2_operand_u18 cVar1;
  c2_node *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_symbol *part;
  c2_operand *src_opnd;
  c2_tuple *conv;
  c2_operand *wrapped_src;
  uint uVar5;
  c2_operand *prev_src;
  c2_operand *prev_src2;
  c2_operand *fwd_dst;
  
  pcVar4 = t->src;
  type = t->type;
  uVar5 = (uint)type;
  if ((pcVar4->type & 0xfff) < (uVar5 & 0xfff)) {
    return (c2_node *)t;
  }
  if ((1 << (byte)(pcVar4->type >> 0xc) & 0xeU) == 0) {
    return (c2_node *)t;
  }
  if ((1 << (byte)(type >> 0xc) & 0xeU) == 0) {
    return (c2_node *)t;
  }
  switch(pcVar4->kind) {
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
    if ((((pcVar4->kind == '\x01') && (pcVar4->sym->cls == '\x03')) &&
        (pcVar4->sym->def != (c2_tuple *)0x0)) && (4 < (pcVar4->type & 0xfff))) {
      return (c2_node *)t;
    }
    pcVar4 = tuple_forward_src_and_free(t,user);
    if ((1 << (pcVar4->kind & 0x1f) & 6U) != 0) {
      part = symbol_get_part(pcVar4->sym,type,uVar5 & 0xfff,0);
      pcVar4->sym = part;
    }
    pcVar4->type = type;
    g_simplify_changed = 1;
    return (c2_node *)pcVar4;
  default:
    goto switchD_1070bf98_caseD_5;
  case '\x06':
    pcVar4 = tuple_forward_src_and_free(t,user);
    g_simplify_changed = 1;
    pcVar4->type = type;
    return (c2_node *)pcVar4;
  case '\a':
  case '\b':
  case '\t':
    pcVar2 = fold_constant_operands(t,user);
    return pcVar2;
  case '\f':
    switch(pcVar4->op) {
    case 0x160:
    case 0x161:
    case 0x16d:
    case 0x16e:
    case 0x16f:
    case 0x172:
    case 0x173:
    case 0x174:
      t = (c2_tuple *)tuple_forward_src_and_free(t,user);
      fwd_dst = (c2_operand *)((c2_operand *)t)->tag;
      ((c2_operand *)t)->type = type;
      part = symbol_get_part(fwd_dst->sym,type,uVar5 & 0xfff,0);
      fwd_dst->sym = part;
      if ((fwd_dst->kind == '\x01') && (part->def != (c2_tuple *)0x0)) {
        (fwd_dst->u18).reg = part;
      }
      fwd_dst->type = type;
      wrapped_src = (((c2_operand *)t)->u18).children;
      if ((((c2_operand *)t)->u18).children != (c2_operand *)0x0) {
        do {
          pcVar4 = wrapped_src->next;
          if ((c2_operand *)t != (c2_operand *)0x0) {
            prev_src = (c2_operand *)
                       list_find_prev((c2_link *)(((c2_operand *)t)->u18).reg,(c2_link *)wrapped_src
                                     );
            tuple_detach_src((c2_node *)t,wrapped_src);
          }
          pcVar3 = operand_new_temp(type);
          conv = tuple_new_unary_temp(0x15f,type,pcVar3,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
          tuple_replace_src(conv,conv->src,wrapped_src);
          conv->flags12 = '\x02';
          if ((c2_operand *)t != (c2_operand *)0x0) {
            if (prev_src == (c2_operand *)0x0) {
              cVar1 = ((c2_operand *)t)->u18;
              (((c2_operand *)t)->u18).reg = (c2_symbol *)conv;
              conv->next = (c2_tuple *)cVar1;
            }
            else {
              tuple_insert_src_after(t,prev_src,(c2_operand *)conv);
            }
          }
          tuple_unlink_mem_subops(conv);
          conv->flags12 = '\x02';
          wrapped_src = pcVar4;
        } while (pcVar4 != (c2_operand *)0x0);
        g_simplify_changed = 1;
        return (c2_node *)(c2_operand *)t;
      }
      break;
    default:
      goto switchD_1070bf98_caseD_5;
    case 0x171:
      t = (c2_tuple *)tuple_forward_src_and_free(t,user);
      fwd_dst = (c2_operand *)((c2_operand *)t)->tag;
      ((c2_operand *)t)->type = type;
      part = symbol_get_part(fwd_dst->sym,type,uVar5 & 0xfff,0);
      fwd_dst->sym = part;
      if ((fwd_dst->kind == '\x01') && (part->def != (c2_tuple *)0x0)) {
        (fwd_dst->u18).reg = part;
      }
      fwd_dst->type = type;
      pcVar4 = (((c2_operand *)t)->u18).children;
      pcVar3 = pcVar4;
      goto joined_r0x1070c295;
    }
    break;
  case '\x10':
    t = (c2_tuple *)tuple_forward_src_and_free(t,user);
    fwd_dst = (c2_operand *)((c2_operand *)t)->tag;
    ((c2_operand *)t)->type = type;
    part = symbol_get_part(fwd_dst->sym,type,uVar5 & 0xfff,0);
    fwd_dst->sym = part;
    if ((fwd_dst->kind == '\x01') && (part->def != (c2_tuple *)0x0)) {
      (fwd_dst->u18).reg = part;
    }
    pcVar4 = (((c2_operand *)t)->u18).children;
    fwd_dst->type = type;
    pcVar3 = pcVar4->next;
    if ((c2_operand *)t != (c2_operand *)0x0) {
      prev_src2 = (c2_operand *)list_find_prev((c2_link *)pcVar4,(c2_link *)pcVar3);
      tuple_detach_src((c2_node *)t,pcVar3);
    }
    src_opnd = operand_new_temp(type);
    conv = tuple_new_unary_temp(0x15f,type,src_opnd,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
    tuple_replace_src(conv,conv->src,pcVar3);
    conv->flags12 = '\x02';
    if ((c2_operand *)t != (c2_operand *)0x0) {
      if (prev_src2 == (c2_operand *)0x0) {
        cVar1 = ((c2_operand *)t)->u18;
        (((c2_operand *)t)->u18).reg = (c2_symbol *)conv;
        conv->next = (c2_tuple *)cVar1;
      }
      else {
        tuple_insert_src_after(t,prev_src2,(c2_operand *)conv);
      }
    }
    tuple_unlink_mem_subops(conv);
    pcVar4 = (((c2_operand *)t)->u18).children;
    conv->flags12 = '\x02';
    pcVar3 = pcVar4->next->next;
joined_r0x1070c295:
    if ((c2_operand *)t != (c2_operand *)0x0) {
      prev_src2 = (c2_operand *)list_find_prev((c2_link *)pcVar4,(c2_link *)pcVar3);
      tuple_detach_src((c2_node *)t,pcVar3);
    }
    pcVar4 = operand_new_temp(type);
    conv = tuple_new_unary_temp(0x15f,type,pcVar4,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
    tuple_replace_src(conv,conv->src,pcVar3);
    conv->flags12 = '\x02';
    if ((c2_operand *)t != (c2_operand *)0x0) {
      if (prev_src2 == (c2_operand *)0x0) {
        cVar1 = ((c2_operand *)t)->u18;
        (((c2_operand *)t)->u18).reg = (c2_symbol *)conv;
        conv->next = (c2_tuple *)cVar1;
      }
      else {
        tuple_insert_src_after(t,prev_src2,(c2_operand *)conv);
      }
    }
    tuple_unlink_mem_subops(conv);
    conv->flags12 = '\x02';
  }
  g_simplify_changed = 1;
switchD_1070bf98_caseD_5:
  return (c2_node *)(c2_operand *)t;
}

