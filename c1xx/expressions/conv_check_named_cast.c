c1_node * __cdecl conv_check_named_cast(c1_type *target,c1_node *node)

{
  char cVar1;
  char cVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  c1_type *pcVar5;
  bool bVar6;
  c1_type *target_00;
  uint uVar7;
  char cVar8;
  c1_u8 cVar9;
  ushort uVar10;
  c1_symbol *sym;
  c1_node *pcVar11;
  c1_type *pcVar12;
  c1_symbol *local_c;
  uint local_8;
  uint local_4;
  
  target_00 = target;
  bVar6 = false;
  if (((target->code & 0x8f) == 0x82) && (((byte)target->base->code >> 6 & 1) != 0)) {
    bVar6 = true;
    local_4 = 4;
  }
  else {
    local_4 = type_classify_class_form(target,(int *)&local_c);
    if (((local_4 & 0xc) == 0) ||
       (((local_c->flags2 & 4) == 0 &&
        (tmpl_instantiate_if_needed(local_c), (local_c->flags2 & 4) == 0)))) {
      diag_error(0x2a8,target_00,0xde);
      return (c1_node *)0x0;
    }
  }
  node = expr_resolve_address_of_overload(node);
  if ((node->kind & 8) != 0) {
    return (c1_node *)0x0;
  }
  pcVar12 = node->type;
  if (((pcVar12->code & 0x8f) == 0x82) &&
     ((uVar10 = pcVar12->flags & 0x18, uVar10 == 0x18 || (uVar10 == 8)))) {
    node = expr_based_pointer_fixup(node);
    pcVar12 = node->type;
  }
  pcVar11 = node;
  if (((pcVar12->code & 0x200) == 0) || ((node->kind & 0x20) != 0)) {
    local_8 = type_classify_class_form(pcVar12,(int *)&target);
    if (local_8 == 2) {
      pcVar12 = conv_array_to_pointer_type(pcVar11);
      pcVar11->type = pcVar12;
      local_8 = type_classify_class_form(pcVar12,(int *)&target);
    }
  }
  else {
    target = (c1_type *)(pcVar12->extra).cls;
    local_8 = 8;
  }
  uVar7 = local_8;
  if ((target != (c1_type *)0x0) && ((target->flags & 4) == 0)) {
    tmpl_instantiate_if_needed((c1_symbol *)target);
  }
  if (((uVar7 & 0xc) != 0) && ((target->flags & 4) != 0)) {
    if (uVar7 == local_4) {
      cVar2 = (char)target_00->code;
      pcVar3 = target_00;
      cVar8 = cVar2;
      while (cVar8 < '\0') {
        pcVar3 = pcVar3->base;
        cVar8 = (char)pcVar3->code;
      }
      cVar1 = (char)pcVar12->code;
      pcVar4 = pcVar12;
      cVar8 = cVar1;
      while (cVar8 < '\0') {
        pcVar4 = pcVar4->base;
        cVar8 = (char)pcVar4->code;
      }
      pcVar5 = pcVar12;
      if ((~pcVar3->flags & pcVar4->flags & 0x3e0) == 0) {
        while (pcVar3 = target_00, cVar1 < '\0') {
          cVar1 = (char)pcVar5->base->code;
          pcVar5 = pcVar5->base;
        }
        while (cVar2 < '\0') {
          cVar2 = (char)pcVar3->base->code;
          pcVar3 = pcVar3->base;
        }
        if (((pcVar3->flags ^ pcVar5->flags) & 0xfc18) == 0) {
          if ((!bVar6) &&
             (sym = class_lookup_qualified_member(g_current_scope,(c1_symbol *)target,local_c,0x80),
             sym != (c1_symbol *)0x0)) {
            cVar8 = access_check_member_path(sym);
            if ((cVar8 != '\0') && (*(c1_type **)sym->type == sym->type->base)) {
              pcVar11 = conv_convert_cast(0xde,target_00,node);
              return pcVar11;
            }
            diag_warning(1,0x21c,pcVar12,target_00);
          }
          cVar9 = class_is_polymorphic((c1_symbol *)target);
          if (cVar9 != '\0') {
            if (g_rtti == '\0') {
              diag_warning(1,0x21d,0xde,target[1].base);
            }
            if (bVar6) {
              pcVar11 = expr_build_rt_cast_to_void_call(node,target_00,(c1_symbol *)target);
            }
            else {
              pcVar11 = expr_build_dynamic_cast_call
                                  (node,target_00,local_c,(c1_symbol *)target,local_8 == 8);
            }
            if (((target_00->code & 0x8f) == 0x82) &&
               ((uVar10 = target_00->flags & 0x18, uVar10 == 0x18 || (uVar10 == 8)))) {
              pcVar12 = type_strip_based(target_00);
              pcVar11->type = pcVar12;
              pcVar11 = type_based_pointer_from_node(target_00,pcVar11);
              pcVar11 = expr_based_pointer_fixup(pcVar11);
            }
            return pcVar11;
          }
          diag_error(0x2ab,target);
          return (c1_node *)0x0;
        }
      }
    }
    diag_error(0x2aa,0xde,pcVar12,target_00);
    return (c1_node *)0x0;
  }
  diag_error(0x2a9,pcVar12,0xde);
  return (c1_node *)0x0;
}

