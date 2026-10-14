c1_node * __cdecl
expr_build_member_access_select
          (c1_symbol *member,c1_type *obj_type,c1_node *obj,c1_symbol *member_local,
          int result_kind_0x20,int obj_is_address,c1_type *obj_type_local,c1_type type_desc,c1_u8 op
          ,c1_symbol *name_sym,c1_node *name)

{
  ushort uVar1;
  bool bVar2;
  byte bVar3;
  c1_node *left;
  c1_node *pcVar4;
  c1_node *left_00;
  c1_type *pcVar5;
  c1_arena *a;
  ushort bits;
  undefined2 type_code;
  undefined2 type_flags;
  
  if (-1 < (char)obj->type->code) {
    result_kind_0x20 = 1;
  }
  if (((obj->kind & 7) == 0) && (obj->op == 0x98)) {
    diag_error(0x113,obj->left);
    return (c1_node *)0x0;
  }
  bVar3 = member->kind & 0x1f;
  if ((bVar3 == 0x11) || (bVar3 == 8)) {
    a = g_arenas + g_expr_arena_index;
    left = (c1_node *)a->cur;
    pcVar4 = (c1_node *)g_arenas[g_expr_arena_index].end;
    a->cur = &left[1].op;
    if (pcVar4 < left + 1) {
      arena_grow(a);
    }
    left->kind = '\x02';
    if ((op == 'P') && (op = 'S', obj_is_address == 0)) {
      obj = expr_build_address_of((c1_node *)CONCAT22(type_desc.flags,type_desc.code),2);
    }
    left->op = op;
    left->left = obj;
    name->left = name_sym;
    left->right = name;
    type_desc.base = (c1_type *)0x0;
    type_desc.debug_index = 0;
    type_desc.code = 0x80c;
    type_desc.flags = 0;
    type_desc.extra.cls = (c1_symbol *)0x0;
    pcVar5 = type_intern(&type_desc);
    left->type = pcVar5;
  }
  else {
    while ((bVar3 = (byte)obj_type->code, (bVar3 & 0x8f) == 0x83 || ((bVar3 & 0x83) == 0x81))) {
      obj_type = obj_type->base;
    }
    if ((char)obj_type->code < '\0') {
      obj_type = obj_type->base;
    }
    if ((obj_type->code & 0x8f) == 0x83) {
      obj_type = type_skip_arrays(obj_type->base);
    }
    bits = obj_type->flags & 0x2e0;
    if ((member_local->flags23 & 4) != 0) {
      bits = obj_type->flags & 0x2c0;
    }
    left = expr_access_checked_member(1,obj,name_sym,1,obj->type);
    if (left->op != 0xe8) {
      obj_type_local = member_local->type;
      left->type = obj_type_local;
    }
    if (bits != 0) {
      pcVar5 = type_with_added_qualifiers(obj_type_local,bits);
      left->type = pcVar5;
    }
    if ((member_local->flags5 & 4) == 0) {
      if ((member_local->kind & 0x1f) == 2) {
        pcVar4 = tree_new_int_constant((uint)(member_local->x28).bytes.depth);
        left_00 = tree_new_int_constant((uint)(member_local->x28).bytes.bit_position);
        pcVar4 = tree_new_binary('6',left_00,pcVar4);
        left = tree_new_binary('5',left,pcVar4);
        if ((member_local->x28).bytes.depth == '\x01') {
          bVar3 = left->flags | 4;
          left->flags = bVar3;
          uVar1 = left->type->code;
          if (((uVar1 & 0x2000) == 0) &&
             (((g_opt_J_unsigned_char == '\0' || (((byte)uVar1 & 0xf) != 1)) ||
              (((uVar1 & 0xfff) == 0x11 && ((uVar1 & 0x1000) != 0)))))) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          left->flags = (!bVar2 ^ bVar3) & 1 ^ bVar3;
        }
        if (bits != 0) {
          pcVar5 = left->type;
          if ((pcVar5->flags & bits) != bits) {
            type_code = pcVar5->code;
            type_flags = pcVar5->flags;
            type_desc.base = pcVar5->base;
            type_desc.extra = pcVar5->extra;
            type_desc.debug_index = pcVar5->debug_index;
            type_desc.flags = type_flags | bits;
            type_desc.code = type_code;
            pcVar5 = type_intern(&type_desc);
          }
          left->type = pcVar5;
        }
      }
      if (left->op != 0xe8) {
        left = expr_member_value(member_local,left);
      }
      if (result_kind_0x20 != 0) {
        left->kind = left->kind | 0x20;
        return left;
      }
    }
  }
  return left;
}

