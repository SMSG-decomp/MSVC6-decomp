c1_node * __cdecl expr_build_member_access(c1_u8 op,c1_node *obj,c1_node *name)

{
  ushort uVar1;
  undefined2 uVar2;
  byte *pbVar3;
  undefined2 uVar4;
  c1_type type_desc_00;
  bool bVar5;
  c1_scope_stack *pcVar6;
  byte bVar7;
  char cVar8;
  int iVar9;
  c1_node *pcVar10;
  c1_symbol *pcVar11;
  c1_node *pcVar12;
  c1_node *left;
  c1_type *obj_type;
  c1_type *pcVar13;
  ushort uVar14;
  c1_arena *a;
  c1_symbol *sym;
  c1_symbol *pcVar15;
  c1_symbol *member_local;
  uint result_kind_0x20;
  int iVar16;
  c1_type type_desc;
  
  pcVar6 = g_current_scope;
  result_kind_0x20 = 0;
  iVar16 = 0;
  g_current_scope->reported = '\0';
  pcVar6->qual_class = (c1_symbol *)0x0;
  pcVar6->access_op = '\x01';
  pcVar6->qualified = '\0';
  if (name == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  if (obj != (c1_node *)0x0) {
    obj_type = obj->type;
    cVar8 = (char)obj_type->code;
    pcVar13 = obj_type;
    while (cVar8 < '\0') {
      pcVar13 = pcVar13->base;
      cVar8 = (char)pcVar13->code;
    }
    if ((pcVar13->code & 0x200) == 0) {
      pcVar11 = (c1_symbol *)0x0;
    }
    else {
      pcVar11 = (pcVar13->extra).cls;
    }
    bVar7 = name->op;
    type_desc._0_4_ = obj;
    if (bVar7 != 6) {
      if (bVar7 == 0x3d) {
        pbVar3 = *(byte **)((int)name->left + 0x10);
        if ((*pbVar3 & 0x1f) == 0xf) {
          diag_error(0x27,0x53,pbVar3,pcVar11);
          return (c1_node *)0x0;
        }
      }
      else {
        if (op == 'S') {
          diag_error(0x111,(uint)bVar7);
          return (c1_node *)0x0;
        }
        diag_error(0x112,(uint)bVar7);
      }
      return (c1_node *)0x0;
    }
    pcVar11 = name->left;
    pcVar15 = pcVar11;
    if ((pcVar11->kind & 0x1f) == 0x12) {
      pcVar15 = *(c1_symbol **)(*(int *)pcVar11->type + 8);
    }
    sym = pcVar15;
    if ((pcVar15->kind & 0x1f) == 0x1a) {
      sym = *(c1_symbol **)pcVar15->type;
    }
    member_local = sym;
    pcVar13 = obj_type;
    iVar9 = sym_is_static_data_member(sym);
    if (iVar9 == 0) {
      if ((sym->kind & 0x1f) == 5) {
        access_check_member(pcVar11);
        pcVar10 = tree_new_value_constant(sym);
        return pcVar10;
      }
      if (op == 'S') {
        uVar14 = obj_type->code & 0x8f;
        if ((((uVar14 != 0x82) && (uVar14 != 0x83)) || ((char)obj_type->base->code < '\0')) &&
           (((cVar8 = (char)obj_type->code, -1 < cVar8 || (uVar14 != 0x80)) ||
            ((char)obj_type->base->code < '\0')))) {
          if (-1 < cVar8) {
            diag_error(0xe8,0x53,pcVar11,obj_type);
            return (c1_node *)0x0;
          }
          diag_error(0xe3,pcVar15->name);
          return (c1_node *)0x0;
        }
      }
      else {
        bVar7 = (byte)obj_type->code;
        if (((char)bVar7 < '\0') && ((bVar7 & 0x8f) == 0x80)) {
          iVar16 = 1;
        }
        else if ((char)bVar7 < '\0') {
          uVar14 = obj_type->code & 0x8f;
          if (((uVar14 == 0x82) || (uVar14 == 0x83)) && (-1 < (char)obj_type->base->code)) {
            diag_error(0xe7,0x53,pcVar11,obj_type);
          }
          else {
            diag_error(0xe4,pcVar15->name);
          }
        }
        else {
          result_kind_0x20 = obj->kind & 0x20;
          obj = (c1_node *)expr_address_of_through_casts(obj);
          if (obj->op == '4') {
            type_desc_00.base = type_desc.base;
            type_desc_00.code = type_desc.code;
            type_desc_00.flags = type_desc.flags;
            type_desc_00.extra.cls = type_desc.extra.cls;
            type_desc_00.debug_index = type_desc.debug_index;
            pcVar10 = expr_build_member_access_select
                                (sym,obj_type,obj,member_local,result_kind_0x20,iVar16,pcVar13,
                                 type_desc_00,op,pcVar11,name);
            return pcVar10;
          }
        }
      }
      if (((obj->kind & 7) == 0) && (obj->op == 0x98)) {
        diag_error(0x113,obj->left);
        return (c1_node *)0x0;
      }
      bVar7 = sym->kind & 0x1f;
      if ((bVar7 == 0x11) || (bVar7 == 8)) {
        a = g_arenas + g_expr_arena_index;
        pcVar10 = (c1_node *)a->cur;
        pcVar12 = (c1_node *)g_arenas[g_expr_arena_index].end;
        a->cur = &pcVar10[1].op;
        if (pcVar12 < pcVar10 + 1) {
          arena_grow(a);
        }
        pcVar10->kind = '\x02';
        if ((op == 'P') && (op = 'S', iVar16 == 0)) {
          obj = expr_build_address_of((c1_node *)type_desc._0_4_,2);
        }
        pcVar10->op = op;
        pcVar10->left = obj;
        name->left = pcVar11;
        pcVar10->right = name;
        type_desc.base = (c1_type *)0x0;
        type_desc.debug_index = 0;
        type_desc.code = 0x80c;
        type_desc.flags = 0;
        type_desc.extra.cls = (c1_symbol *)0x0;
        pcVar13 = type_intern(&type_desc);
        pcVar10->type = pcVar13;
      }
      else {
        while ((bVar7 = (byte)obj_type->code, (bVar7 & 0x8f) == 0x83 || ((bVar7 & 0x83) == 0x81))) {
          obj_type = obj_type->base;
        }
        if ((char)obj_type->code < '\0') {
          obj_type = obj_type->base;
        }
        if ((obj_type->code & 0x8f) == 0x83) {
          obj_type = type_skip_arrays(obj_type->base);
        }
        uVar14 = obj_type->flags & 0x2e0;
        if ((member_local->flags23 & 4) != 0) {
          uVar14 = obj_type->flags & 0x2c0;
        }
        pcVar10 = expr_access_checked_member(1,obj,pcVar11,1,obj->type);
        if (pcVar10->op != 0xe8) {
          pcVar13 = member_local->type;
          pcVar10->type = pcVar13;
        }
        if (uVar14 != 0) {
          pcVar13 = type_with_added_qualifiers(pcVar13,uVar14);
          pcVar10->type = pcVar13;
        }
        if ((member_local->flags5 & 4) == 0) {
          if ((member_local->kind & 0x1f) == 2) {
            pcVar12 = tree_new_int_constant((uint)(member_local->x28).bytes.depth);
            left = tree_new_int_constant((uint)(member_local->x28).bytes.bit_position);
            pcVar12 = tree_new_binary('6',left,pcVar12);
            pcVar10 = tree_new_binary('5',pcVar10,pcVar12);
            if ((member_local->x28).bytes.depth == '\x01') {
              bVar7 = pcVar10->flags | 4;
              pcVar10->flags = bVar7;
              uVar1 = pcVar10->type->code;
              if (((uVar1 & 0x2000) == 0) &&
                 (((g_opt_J_unsigned_char == '\0' || (((byte)uVar1 & 0xf) != 1)) ||
                  (((uVar1 & 0xfff) == 0x11 && ((uVar1 & 0x1000) != 0)))))) {
                bVar5 = true;
              }
              else {
                bVar5 = false;
              }
              pcVar10->flags = (!bVar5 ^ bVar7) & 1 ^ bVar7;
            }
            if (uVar14 != 0) {
              pcVar13 = pcVar10->type;
              if ((pcVar13->flags & uVar14) != uVar14) {
                uVar2 = pcVar13->code;
                uVar4 = pcVar13->flags;
                type_desc.base = pcVar13->base;
                type_desc.extra = pcVar13->extra;
                type_desc.debug_index = pcVar13->debug_index;
                type_desc.flags = uVar4 | uVar14;
                type_desc.code = uVar2;
                pcVar13 = type_intern(&type_desc);
              }
              pcVar10->type = pcVar13;
            }
          }
          if (pcVar10->op != 0xe8) {
            pcVar10 = expr_member_value(member_local,pcVar10);
          }
          if (result_kind_0x20 != 0) {
            pcVar10->kind = pcVar10->kind | 0x20;
            return pcVar10;
          }
        }
      }
    }
    else {
      access_check_member(pcVar11);
      iVar16 = 0;
      pcVar11 = sym_static_member_stand_in(sym);
      pcVar10 = expr_reference_named_entity(pcVar11,iVar16);
      type_desc.base = (c1_type *)0xff;
      type_desc.code = 0xd9bc;
      type_desc.flags = 0x104b;
      cVar8 = tree_has_side_effects((c1_tree_visitor *)&type_desc,obj);
      if (cVar8 != '\0') {
        pcVar10 = tree_new_binary_typed_right('7',obj,pcVar10);
        return pcVar10;
      }
    }
    return pcVar10;
  }
  return (c1_node *)0x0;
}

