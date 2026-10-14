c2_tuple * __fastcall widen_conversion_pushdown(c2_tuple *t,c2_tuple *parent)

{
  ushort type;
  ushort uVar1;
  uint uVar2;
  c2_tuple *inner;
  c2_symbol *part_sym;
  c2_operand *new_temp;
  c2_operand *src;
  c2_tuple *src_conv;
  ushort uVar3;
  uint16_t type_00;
  uint uVar4;
  uint uVar5;
  c2_tuple *result;
  c2_operand *prev_src;
  c2_operand *wrapped_src;
  c2_operand *inner_dst;
  c2_operand *next_opnd;
  
  if (t->op == 0x15f) {
    type = t->type;
    uVar1 = t->src->type;
    uVar2 = (uint)uVar1;
    uVar3 = type & 0xfff;
    uVar5 = (type ^ uVar1) & 0xfff;
    uVar4 = uVar5 ^ uVar2;
    if (((((uVar1 & 0xfff) < uVar3) && ((1 << (byte)(uVar1 >> 0xc) & 0xeU) != 0)) &&
        ((1 << (byte)(type >> 0xc) & 0xeU) != 0)) && (uVar3 < 5)) {
      switch(t->src->op) {
      case 0x161:
        if (((uVar2 & 0xf000) == 0x2000) && ((short)uVar5 != 0)) {
          return t;
        }
        break;
      default:
        goto switchD_10709749_caseD_162;
      case 0x172:
      case 0x173:
      case 0x174:
        break;
      case 0x177:
        if (((uVar2 & 0xf000) == 0x1000) && ((type & 0xf000) == 0x2000)) {
          return t;
        }
      }
      if (uVar3 != 2) {
        inner = (c2_tuple *)tuple_forward_src_and_free(t,parent);
        inner_dst = inner->dst;
        part_sym = inner_dst->sym;
        type_00 = (uint16_t)uVar4;
        inner->type = type_00;
        part_sym = symbol_get_part(part_sym,type_00,uVar4 & 0xfff,0);
        inner_dst->sym = part_sym;
        if ((inner_dst->kind == '\x01') && (part_sym->def != (c2_tuple *)0x0)) {
          (inner_dst->u18).reg = part_sym;
        }
        inner_dst->type = type_00;
        result = inner;
        if (type_00 != type) {
          if (parent != (c2_tuple *)0x0) {
            prev_src = (c2_operand *)list_find_prev((c2_link *)parent->src,(c2_link *)inner);
            tuple_detach_src((c2_node *)parent,(c2_operand *)inner);
          }
          new_temp = operand_new_temp(type);
          result = tuple_new_unary_temp(0x15f,type,new_temp,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
          tuple_replace_src(result,(((c2_operand *)result)->u18).children,(c2_operand *)inner);
          *(undefined1 *)&((c2_operand *)result)->x12 = 2;
          if (parent != (c2_tuple *)0x0) {
            if (prev_src == (c2_operand *)0x0) {
              new_temp = parent->src;
              parent->src = (c2_operand *)result;
              ((c2_operand *)result)->next = new_temp;
            }
            else {
              tuple_insert_src_after(parent,prev_src,(c2_operand *)result);
            }
          }
          tuple_unlink_mem_subops(result);
          *(undefined1 *)&((c2_operand *)result)->x12 = 2;
        }
        new_temp = inner->src;
        while (new_temp != (c2_operand *)0x0) {
          next_opnd = new_temp->next;
          if (inner != (c2_tuple *)0x0) {
            prev_src = (c2_operand *)list_find_prev((c2_link *)inner->src,(c2_link *)new_temp);
            tuple_detach_src((c2_node *)inner,new_temp);
          }
          src = operand_new_temp(type_00);
          src_conv = tuple_new_unary_temp(0x15f,type_00,src,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
          tuple_replace_src(src_conv,src_conv->src,new_temp);
          src_conv->flags12 = '\x02';
          if (inner != (c2_tuple *)0x0) {
            if (prev_src == (c2_operand *)0x0) {
              wrapped_src = inner->src;
              inner->src = (c2_operand *)src_conv;
              src_conv->next = (c2_tuple *)wrapped_src;
            }
            else {
              tuple_insert_src_after(inner,prev_src,(c2_operand *)src_conv);
            }
          }
          tuple_unlink_mem_subops(src_conv);
          src_conv->flags12 = '\x02';
          new_temp = next_opnd;
        }
        g_simplify_changed = 1;
        t = result;
      }
    }
  }
switchD_10709749_caseD_162:
  return t;
}

