c2_node * __fastcall
narrow_conversion_into_operator(c2_tuple *parent,c2_tuple *convert,c2_tuple *user)

{
  ushort type;
  ushort uVar1;
  c2_operand *op;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_node *pcVar4;
  c2_operand *temp;
  c2_tuple *child;
  uint8_t uVar5;
  undefined4 unaff_EBP;
  c2_operand *type_00;
  c2_operand *prev_src;
  
  type = convert->src->type;
  type_00 = (c2_operand *)CONCAT22((short)((uint)unaff_EBP >> 0x10),type);
  uVar1 = parent->type;
  if ((((ushort)(type & 0xfff) <= (uVar1 & 0xfff)) && ((1 << (byte)(type >> 0xc) & 0xeU) != 0)) &&
     ((1 << (byte)(uVar1 >> 0xc) & 0xeU) != 0)) {
    switch(parent->op) {
    case 0x172:
    case 0x173:
    case 0x174:
      pcVar4 = narrow_operator_operands(parent,(c2_node *)convert,type,user);
      return pcVar4;
    case 0x177:
      if (((((type & 0xf000) == 0x1000) == ((uVar1 & 0xf000) == 0x1000)) ||
          ((type & 0xf000) == 0x2000)) && (pcVar3 = parent->src, (c2_operand *)convert == pcVar3)) {
        op = pcVar3->next;
        prev_src = type_00;
        if (parent != (c2_tuple *)0x0) {
          prev_src = (c2_operand *)list_find_prev((c2_link *)pcVar3,(c2_link *)op);
          tuple_detach_src((c2_node *)parent,op);
        }
        temp = operand_new_temp(type);
        child = tuple_new_unary_temp(0x15f,type,temp,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
        tuple_replace_src(child,child->src,op);
        child->flags12 = '\x02';
        if (parent != (c2_tuple *)0x0) {
          if (prev_src == (c2_operand *)0x0) {
            pcVar3 = parent->src;
            parent->src = (c2_operand *)child;
            child->next = (c2_tuple *)pcVar3;
          }
          else {
            tuple_insert_src_after(parent,prev_src,(c2_operand *)child);
          }
        }
        tuple_unlink_mem_subops(child);
        child->flags12 = '\x02';
        pcVar2 = narrow_operator_through_conversion(parent,convert,(uint32_t)type_00,user);
        return (c2_node *)pcVar2;
      }
      break;
    case 0x17d:
      if (user == (c2_tuple *)0x0) {
        uVar5 = (uint8_t)g_simplify_context_tuple->type;
      }
      else {
        uVar5 = (user->u20).cc;
      }
      if ((uVar5 != '\x02') && (uVar5 != '\x01')) {
        if ((((uint)uVar1 ^ (uint)type_00) & 0xfff) == 0) {
          return (c2_node *)0x0;
        }
        if (((uVar1 & 0xf000) == 0x2000) && ((type & 0xf000) == 0x1000)) {
          type_00 = (c2_operand *)(type & 0xfff | 0x2000);
        }
      }
      pcVar3 = parent->src;
      if ((pcVar3->op == 0x15f) && (pcVar3->next->op == 0x15f)) {
        if (pcVar3 == (c2_operand *)convert) {
          pcVar3 = pcVar3->next;
        }
        uVar1 = ((pcVar3->u18).children)->type;
        if (((type & 0xf000) == 0x1000) != ((uVar1 & 0xf000) == 0x1000)) {
          if ((type & 0xf000) == 0x2000) {
            return (c2_node *)0x0;
          }
          if ((type & 0xfff) <= (uVar1 & 0xfff)) {
            return (c2_node *)0x0;
          }
        }
      }
      pcVar2 = (c2_tuple *)
               narrow_operator_operands(parent,(c2_node *)convert,(uint16_t)type_00,user);
      if (pcVar2 == (c2_tuple *)0x0) {
        return (c2_node *)0x0;
      }
      if (pcVar2 != parent) {
        tuple_forward_src_and_free(pcVar2,user);
        return (c2_node *)parent;
      }
      return (c2_node *)pcVar2;
    }
  }
  return (c2_node *)0x0;
}

