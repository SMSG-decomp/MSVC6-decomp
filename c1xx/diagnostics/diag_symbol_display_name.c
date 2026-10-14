char * __cdecl diag_symbol_display_name(c1_symbol *sym)

{
  c1_u8 *pcVar1;
  char cVar2;
  c1_u8 *pcVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  void *pvVar9;
  uint uVar10;
  uint uVar11;
  c1_u32 *pcVar12;
  c1_type *type;
  c1_symbol *cls;
  c1_symbol *cls_00;
  c1_u32 *name_words;
  c1_symbol *pcVar13;
  char *pcVar14;
  c1_u32 *name_words_2;
  
  if ((sym->kind & 0x1f) == 0x12) {
    cls = *(c1_symbol **)(*(int *)sym->type + 8);
    pcVar13 = sym;
  }
  else {
    pcVar13 = (c1_symbol *)0x0;
    cls = sym;
  }
  bVar4 = cls->kind & 0x1f;
  if (((bVar4 == 0x10) || (bVar4 == 0x11)) || (bVar4 == 0x1b)) {
    cls = (c1_symbol *)&cls->type[-1].extra;
  }
  bVar4 = cls->flags1;
  if ((bVar4 & 0x40) == 0) {
    bVar5 = cls->kind & 0x1f;
    if (((bVar5 != 7) && (bVar5 != 8)) ||
       ((((bVar4 & 0x10) != 0x10 &&
         (((bVar4 & 0x20) != 0x20 && (cls->name != g_name_scalar_deleting_dtor)))) &&
        (cls->name != g_name_vector_deleting_dtor)))) {
      pcVar8 = cls->name->text;
      if (bVar5 == 0xf) {
        cls = g_scope_vector->entries[(short)cls->key_ref];
      }
      if (((cls->kind & 0x1f) == 4) && ((((cls->detail).cls)->flags3e & 1) != 0)) {
        iVar6 = format_buffer_acquire();
        format_buffer_free(iVar6);
        iVar6 = format_class_name(cls);
        pcVar8 = format_buffer_text(iVar6);
        format_buffer_leave();
        return pcVar8;
      }
      if ((cls->name != (fe_name *)0x0) && ((cls->name->flags & 0x2000000) != 0)) {
        iVar6 = format_buffer_acquire();
        format_buffer_free(iVar6);
        iVar6 = format_undecorated_name(0,cls->name);
        pcVar8 = format_buffer_text(iVar6);
        format_buffer_leave();
        return pcVar8;
      }
      if ((*pcVar8 != '?') && ((*pcVar8 != ' ' || (g_error_count == 0)))) {
        return pcVar8;
      }
      if (g_esumem_copy_table != (c1_symtab *)0x0) {
        pvVar9 = symtab_lookup(g_esumem_copy_table,pcVar8);
        if (pvVar9 != (void *)0x0) {
          return *(char **)(*(int *)((int)pvVar9 + 8) + 4);
        }
      }
      iVar6 = format_undecorated_name(0,cls->name);
      pcVar8 = format_buffer_text(iVar6);
      return pcVar8;
    }
    cls_00 = g_scope_vector->entries[(short)cls->scope_index];
    if (cls_00 == (c1_symbol *)0x0) {
      if (pcVar13 == (c1_symbol *)0x0) {
        diag_fatal_simple(0x1fb);
      }
      cls_00 = *(c1_symbol **)(**(int **)pcVar13->type + 8);
    }
    if ((cls_00->kind & 0x1f) == 0xf) {
      cls_00 = g_scope_vector->entries[(short)cls_00->key_ref];
    }
    if ((((cls_00->detail).cls)->flags3e & 1) == 0) {
      pcVar8 = cls_00->name->text;
    }
    else {
      iVar6 = format_buffer_acquire();
      format_buffer_free(iVar6);
      iVar6 = format_class_name(cls_00);
      pcVar8 = format_buffer_text(iVar6);
      format_buffer_leave();
    }
    pcVar3 = g_arenas[9].cur;
    uVar10 = 0xffffffff;
    pcVar7 = pcVar8;
    do {
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    iVar6 = ~uVar10 - 1;
    g_arenas[9].cur = g_arenas[9].cur + (~uVar10 + 6 + iVar6 & 0xfffffffc);
    if (g_arenas[9].end < g_arenas[9].cur) {
      arena_grow(g_arenas + 9);
    }
    uVar10 = 0xffffffff;
    pcVar7 = pcVar8;
    do {
      pcVar14 = pcVar7;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      pcVar14 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar14;
    } while (cVar2 != '\0');
    uVar10 = ~uVar10;
    pcVar12 = (c1_u32 *)(pcVar14 + -uVar10);
    name_words_2 = (c1_u32 *)pcVar3;
    for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *name_words_2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      name_words_2 = name_words_2 + 1;
    }
    pcVar1 = pcVar3 + iVar6;
    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(char *)name_words_2 = (char)*pcVar12;
      pcVar12 = (c1_u32 *)((int)pcVar12 + 1);
      name_words_2 = (c1_u32 *)((int)name_words_2 + 1);
    }
    *pcVar1 = ':';
    pcVar1[1] = ':';
    pcVar12 = (c1_u32 *)(pcVar1 + 2);
    if ((((cls->flags1 & 0x20) == 0x20) || (cls->name == g_name_scalar_deleting_dtor)) ||
       (cls->name == g_name_vector_deleting_dtor)) {
      *(c1_u8 *)pcVar12 = '~';
      pcVar12 = (c1_u32 *)(pcVar1 + 3);
    }
    uVar10 = 0xffffffff;
    do {
      pcVar7 = pcVar8;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      pcVar7 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar7;
    } while (cVar2 != '\0');
    uVar10 = ~uVar10;
    name_words = (c1_u32 *)(pcVar7 + -uVar10);
    for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *pcVar12 = *name_words;
      name_words = name_words + 1;
      pcVar12 = pcVar12 + 1;
    }
    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(c1_u8 *)pcVar12 = (c1_u8)*name_words;
      name_words = (c1_u32 *)((int)name_words + 1);
      pcVar12 = (c1_u32 *)((int)pcVar12 + 1);
    }
    return (char *)pcVar3;
  }
  type = cls->type;
  if ((type->code & 0x83) == 0x81) {
    type = type->base;
  }
  iVar6 = format_buffer_acquire();
  format_buffer_free(iVar6);
  iVar6 = format_symbol_declaration_text((c1_symbol *)0x0,type);
  pcVar7 = format_buffer_text(iVar6);
  pcVar3 = g_arenas[9].cur;
  uVar10 = 0xffffffff;
  pcVar8 = pcVar7;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  uVar10 = ~uVar10;
  g_arenas[9].cur = g_arenas[9].cur + (uVar10 + 0xd & 0xfffffffc);
  if (g_arenas[9].end < g_arenas[9].cur) {
    arena_grow(g_arenas + 9);
  }
  strncpy((char *)pcVar3,"operator`",9);
  strncpy((char *)(pcVar3 + 9),pcVar7,uVar10 - 1);
  pcVar3[uVar10 + 8] = '\'';
  pcVar3[uVar10 + 9] = '\0';
  format_buffer_free(iVar6);
  format_buffer_leave();
  return (char *)pcVar3;
}

