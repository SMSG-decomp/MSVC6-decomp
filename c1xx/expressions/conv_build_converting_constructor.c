c1_node * __thiscall conv_build_converting_constructor(c1_conversion *conv,c1_node *dest)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_node *pcVar6;
  c1_type *pcVar7;
  c1_symbol *pcVar8;
  int kind;
  int flag;
  int do_delete;
  c1_symbol *sym;
  
  if (dest == (c1_node *)0x0) {
    if ((((conv->mode < 4) || (9 < conv->mode)) &&
        ((*(byte *)((int)&((conv->via).function)->tail + 8) & 0x20) != 0)) &&
       (((*(byte *)((int)&((conv->via).function)->tail + 9) & 0x10) != 0 &&
        ((conv->target->extra).cls == (conv->source->extra).cls)))) {
      return conv->expr;
    }
    cVar1 = conv_constructor_ice_check(conv,conv);
    if (cVar1 != '\0') {
      pcVar4 = conv_build_class_argument_in_slot(conv);
      return pcVar4;
    }
    pcVar4 = expr_new_reference_temporary(conv->target);
    conv->target_kind = 1;
  }
  else {
    uVar3 = dest->type->code;
    pcVar4 = dest;
    if (((-1 < (char)uVar3) || ((uVar3 = uVar3 & 0x8f, uVar3 != 0x86 && (uVar3 != 0x82)))) &&
       (pcVar4 = expr_build_address_of(dest,2), pcVar4 == dest)) {
      pcVar7 = type_pointer_with_qualifiers(dest->type,0);
      dest->type = pcVar7;
      pcVar4 = dest;
    }
  }
  pcVar5 = tree_append_list_item((c1_node *)0x0,conv->expr,2);
  conv->first->expr = conv->expr;
  class_redeclare_member_with_access((int)conv->via,(int)conv->target);
  pcVar5 = expr_build_call_node((conv->via).function,pcVar4,(int)pcVar5,(int)(conv->first + -1),1,0)
  ;
  if ((conv->target_symbol == (c1_symbol *)0x0) ||
     ((bVar2 = conv->target_symbol->storage & 7, 3 < bVar2 && (bVar2 < 7)))) {
    pcVar7 = conv->target;
    if ((pcVar7->code & 0x200) == 0) {
      if (((char)pcVar7->code < '\0') && ((pcVar7->base->code & 0x200) != 0)) {
        pcVar8 = (pcVar7->base->extra).cls;
      }
      else {
        pcVar8 = (c1_symbol *)0x0;
      }
    }
    else {
      pcVar8 = (pcVar7->extra).cls;
    }
    bVar2 = class_has_special_member_kind(pcVar8,4);
    if (bVar2 != 0) {
      if ((pcVar7->code & 0x200) == 0) {
        if (((char)pcVar7->code < '\0') && ((pcVar7->base->code & 0x200) != 0)) {
          pcVar8 = (pcVar7->base->extra).cls;
        }
        else {
          pcVar8 = (c1_symbol *)0x0;
        }
      }
      else {
        pcVar8 = (pcVar7->extra).cls;
      }
      if ((((pcVar8->detail).cls)->implicit_state41 & 0x10) == 0) {
        pcVar8 = (conv->target->extra).cls;
        do_delete = 0;
        flag = 1;
        kind = 3;
        sym = pcVar8;
        pcVar6 = tree_copy_to_arena(pcVar4,g_expr_arena_index);
        pcVar6 = expr_build_destructor_call(pcVar8,pcVar6,kind,flag,do_delete);
        pcVar5 = expr_build_eh_state_update(pcVar5,pcVar6,sym);
      }
    }
  }
  if (pcVar5 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar4 = conv_register_target_destructor(conv,pcVar4,pcVar5);
  if ((conv->mode == '\x02') || (conv->mode == '\x03')) {
    conv_check_nonlvalue_to_reference(conv,conv->target,'\x01');
  }
  return pcVar4;
}

