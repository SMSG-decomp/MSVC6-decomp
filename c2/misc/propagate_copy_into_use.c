c2_operand * __fastcall propagate_copy_into_use(c2_operand *use,c2_tuple *user)

{
  byte bVar1;
  ushort type;
  uint16_t type_00;
  uint uVar2;
  uint uVar3;
  c2_symbol *pcVar4;
  uint32_t uVar5;
  c2_operand *after;
  c2_operand *replacement;
  uint uVar6;
  c2_operand *use_opnd;
  uint64_t uVar7;
  uint use_type;
  c2_tuple *copy;
  c2_operand *copy_src;
  
  uVar2 = 1 << (use->kind & 0x1f) & 0x60;
  use_opnd = use;
  if (uVar2 != 0) {
    use_opnd = use->base;
  }
  copy = use_opnd->sym->def;
  copy_src = copy->src;
  bVar1 = copy_src->kind;
  if ((bVar1 == 4) ||
     ((((g_opt_dlp != 0 && ((bVar1 == 3 || (bVar1 == 5)))) || (copy->flags12 == '\x01')) ||
      ((copy_src->next != (c2_operand *)0x0 ||
       ((((uVar2 != 0 && ((1 << (bVar1 & 0x1f) & 0x1eU) == 0)) ||
         (((use_opnd->type ^ copy_src->type) & 0xfff) != 0)) ||
        (((copy_src->flags9 & 1) != 0 &&
         (uVar5 = decide_tree_substitution((c2_tuple *)copy_src,(c2_operand *)0x0), uVar5 != 0))))))
      )))) {
    return use;
  }
  uVar3 = 1 << (copy_src->kind & 0x1f);
  uVar6 = uVar3 & 0x18;
  if (uVar6 == 0) {
    type = use_opnd->type;
  }
  else {
    type = use->type;
  }
  use_type = (uint)type;
  replacement = copy_src;
  if (((uVar3 & 6) == 0) && ((uVar6 == 0 || (uVar2 == 0)))) {
    if (((copy_src->flags9 & 1) != 0) && (type_00 = use->type, type_00 != copy_src->type)) {
      after = (c2_operand *)user;
      if (copy != (c2_tuple *)0x0) {
        after = (c2_operand *)list_find_prev((c2_link *)copy->src,(c2_link *)copy_src);
        tuple_detach_src((c2_node *)copy,copy_src);
      }
      replacement = operand_new_temp(type_00);
      replacement = (c2_operand *)
                    tuple_new_unary_temp
                              (0x15f,type_00,replacement,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
      tuple_replace_src((c2_tuple *)replacement,(replacement->u18).children,copy_src);
      *(undefined1 *)&replacement->x12 = 2;
      if (copy != (c2_tuple *)0x0) {
        if (after == (c2_operand *)0x0) {
          copy_src = copy->src;
          copy->src = replacement;
          replacement->next = copy_src;
        }
        else {
          tuple_insert_src_after(copy,after,replacement);
        }
      }
    }
  }
  else {
    pcVar4 = copy_src->sym;
    if (pcVar4->storage->size < (int)(pcVar4->offset + (use_type & 0xfff))) {
      return use;
    }
    pcVar4 = symbol_get_part(pcVar4,type,use_type & 0xfff,use_opnd->sym->offset);
    copy_src->sym = pcVar4;
  }
  tuple_detach_src((c2_node *)copy,replacement);
  if (((1 << (replacement->kind & 0x1f) & 0xffeU) != 0) &&
     (replacement->type = type, replacement->kind == 7)) {
    uVar7 = const_normalize(type,(replacement->u18).lo,replacement->tag);
    replacement->u18 = (c2_operand_u18)(int)uVar7;
    replacement->tag = (int)(uVar7 >> 0x20);
  }
  if (uVar2 != 0) {
    if (replacement->kind != '\x03') {
      bVar1 = replacement->flags;
      use->base = replacement;
      replacement->flags = bVar1 | 0x30;
      node_free((c2_node *)use_opnd);
      replacement = use;
      goto LAB_107442df;
    }
    operand_to_memory_form(replacement);
  }
  if (user != (c2_tuple *)0x0) {
    tuple_replace_src(user,use,replacement);
  }
LAB_107442df:
  symbol_free_chain(copy->dst->sym->storage);
  node_free((c2_node *)copy);
  return replacement;
}

