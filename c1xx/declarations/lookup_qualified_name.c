c1_keyed_list * __cdecl
lookup_qualified_name(c1_keyed_list *qualifier,void *name,c1_type *conv_type,char p4)

{
  char cVar1;
  c1_type *pcVar2;
  fe_name *pfVar3;
  c1_keyed_cell *item;
  c1xx_hash_scope *scope;
  uint uVar4;
  byte bVar5;
  byte *pbVar6;
  c1_symbol *pcVar7;
  c1_symbol *pcVar8;
  c1_keyed_list *pcVar9;
  fe_name *pfVar10;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar11;
  c1_keyed_cell *pcVar12;
  c1_lookup_result *pcVar13;
  c1_u8 *pcVar14;
  uint uVar15;
  uint uVar16;
  c1_using_directive *directive;
  c1_lookup_result *pcVar17;
  c1xx_hash_scope *ns_scope_2;
  c1xx_hash_scope *ns_scope;
  
  pcVar12 = qualifier->head;
  pcVar8 = pcVar12->sym;
  bVar5 = pcVar8->kind & 0x1f;
  if ((bVar5 == 0xf) || (bVar5 == 0x19)) {
LAB_10418941:
    if (bVar5 != 4) goto LAB_104189f7;
  }
  else {
    if (bVar5 == 0x16) {
LAB_1045b57b:
      if ((p4 == '\0') &&
         ((g_ms_extensions == '\0' || ((g_paren_level_flags[g_paren_depth] & 1) != 0)))) {
        p4 = '\0';
      }
      else {
        p4 = '\x01';
      }
      pcVar8 = sym_new_dependent_name_placeholder(name,p4);
      pcVar9 = tree_new_list_cell((c1_keyed_list *)0x0,(int)qualifier->head,pcVar8);
      return pcVar9;
    }
    if (bVar5 == 1) {
      pcVar2 = pcVar8->type;
      cVar1 = (char)pcVar2->code;
      while (cVar1 < '\0') {
        pcVar2 = pcVar2->base;
        cVar1 = (char)pcVar2->code;
      }
      if ((pcVar2->code & 0xfff) == 0x802) goto LAB_1045b57b;
    }
    pcVar2 = pcVar8->type;
    if ((pcVar2 != (c1_type *)0x0) && ((pcVar2->code & 0x800) != 0)) goto LAB_1045b57b;
    if (bVar5 == 4) {
      if (pcVar2 != (c1_type *)0x0) {
        cVar1 = (char)pcVar2->code;
        while (cVar1 < '\0') {
          pcVar2 = pcVar2->base;
          cVar1 = (char)pcVar2->code;
        }
        if ((pcVar2->code & 0xfff) == 0x802) {
          return qualifier;
        }
      }
      goto LAB_10418941;
    }
LAB_104189f7:
    if (bVar5 != 0x19) {
      if (bVar5 == 0xf) {
        if ((pcVar8->key_ref & 0x20000) != 0) {
          if ((p4 == '\0') &&
             ((g_ms_extensions == '\0' || ((g_paren_level_flags[g_paren_depth] & 1) != 0)))) {
            p4 = '\0';
          }
          else {
            p4 = '\x01';
          }
          pcVar8 = sym_new_dependent_name_placeholder(name,p4);
          pcVar9 = tree_new_list_cell((c1_keyed_list *)0x0,(int)qualifier->head,pcVar8);
          return pcVar9;
        }
        pcVar8 = g_scope_vector->entries[(short)pcVar8->key_ref];
      }
      else {
        pfVar3 = pcVar8->name;
        item = pcVar12->key;
        if (((pcVar8->flags2 & 0x10) == 0) || ((pcVar8->type->code & 0x200) == 0)) {
          if ((pcVar8->flags2 & 0x20) == 0) {
            if (item != (c1_keyed_cell *)0x0) {
              class_lookup_member_set(g_current_scope,item->sym,pfVar3,1,0x181);
            }
          }
          else {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x10;
            expr_resolve_overload_set_member(pcVar8,(c1_symbol *)0x0);
            g_compile_flags_c4 = g_compile_flags_c4 & 0xffffffef;
          }
          if (g_current_scope->qualified == '\0') {
            pcVar14 = class_lookup_qualified_name(g_current_scope,pfVar3);
            if (pcVar14 == (c1_u8 *)0x0) {
              pcVar8 = (c1_symbol *)0x0;
            }
            else {
              pcVar8 = *(c1_symbol **)pcVar14;
            }
          }
          else {
            pcVar8 = class_lookup_member_set
                               (g_current_scope,g_current_scope->qual_class,pfVar3,1,0x181);
          }
          if (pcVar8 == (c1_symbol *)0x0) {
            diag_error(0x1fe,pfVar3);
            return (c1_keyed_list *)0x0;
          }
          if ((pcVar8->kind & 0x1f) == 0x12) {
            pcVar12 = lookup_qualifier_chain_splice(*(c1_keyed_cell **)pcVar8->type,item);
            qualifier->head = pcVar12;
          }
          else {
            tree_list_arena_set(4);
            qualifier = tree_new_list_cell((c1_keyed_list *)0x0,(int)item,pcVar8);
            tree_list_arena_restore();
          }
          pcVar8 = qualifier->head->sym;
          if ((pcVar8->kind & 0x1f) == 0xf) {
            pcVar8 = g_scope_vector->entries[(short)pcVar8->key_ref];
          }
        }
        else {
          pcVar8 = (pcVar8->type->extra).cls;
          pcVar12->sym = pcVar8;
        }
      }
    }
  }
  if ((pcVar8->kind & 0x1f) == 4) {
    if (((g_compile_flags_cc & 0x300000) == 0) && ((((pcVar8->detail).cls)->flags3e & 2) != 0)) {
      diag_error(0x3bb,pcVar8);
      pcVar8->flags3 = pcVar8->flags3 | 4;
    }
    if ((pcVar8->flags2 & 4) == 0) {
      tmpl_instantiate_if_needed(pcVar8);
      goto LAB_10418a2a;
    }
  }
  else {
LAB_10418a2a:
    if (((pcVar8->flags2 & 4) == 0) && ((g_compile_flags_cc & 0x300000) == 0)) {
      if ((g_compile_flags_c4 & 0x10000000) != 0) {
        pcVar8 = sym_new_kind1_placeholder(name);
        pcVar9 = tree_new_list_cell((c1_keyed_list *)0x0,(int)qualifier->head,pcVar8);
        return pcVar9;
      }
      pfVar3 = pcVar8->name;
      pfVar10 = class_current_definition_name();
      if (pfVar3 != pfVar10) {
        if (g_opt_Zg == '\0') {
          diag_error(0x1b,pcVar8);
        }
        return (c1_keyed_list *)0x0;
      }
      pcVar8 = class_current_member_lookup(name);
      if (pcVar8 == (c1_symbol *)0x0) {
        return (c1_keyed_list *)0x0;
      }
      bVar5 = pcVar8->kind & 0x1f;
      if (bVar5 != 4) {
        if (bVar5 != 10) {
          return (c1_keyed_list *)0x0;
        }
        if ((pcVar8->storage & 7) != 7) {
          return (c1_keyed_list *)0x0;
        }
      }
      pcVar9 = tree_new_list_cell((c1_keyed_list *)0x0,(int)qualifier->head,pcVar8);
      return pcVar9;
    }
  }
  if ((pcVar8->kind & 0x1f) == 0x19) {
    ns_scope_2 = *(c1xx_hash_scope **)pcVar8->type;
    result = (*ns_scope_2->vtbl->lookup)(ns_scope_2,name,1);
    if (result != (c1_lookup_result *)0x0) {
LAB_10418ab7:
      pcVar11 = lookup_check_ambiguous_symbol(result,'\x01');
      pcVar7 = (c1_symbol *)ovl_make_set_of_two(pcVar8,pcVar11->sym);
      goto LAB_104189d2;
    }
    directive = ns_scope_2->usings;
    if (directive != (c1_using_directive *)0x0) {
      uVar15 = 0xffffffff;
      pcVar17 = result;
      do {
        scope = directive->ns->info->scope;
        pcVar13 = (*scope->vtbl->lookup)(scope,name,1);
        uVar16 = uVar15;
        result = pcVar17;
        if (pcVar13 != (c1_lookup_result *)0x0) {
          uVar4 = directive->depth;
          if (((uVar4 <= uVar15) && (uVar16 = uVar4, result = pcVar13, uVar15 <= uVar4)) &&
             (uVar16 = uVar15, pcVar17 != (c1_lookup_result *)0x0)) {
            pcVar11 = pcVar13->tail;
            if (pcVar17->head == (c1_lookup_entry *)0x0) {
              pcVar17->head = pcVar13->head;
              pcVar17->tail = pcVar11;
              result = pcVar17;
            }
            else {
              pcVar17->tail->next = pcVar13->head;
              pcVar17->tail = pcVar11;
              result = pcVar17;
            }
          }
        }
        directive = directive->next;
        uVar15 = uVar16;
        pcVar17 = result;
      } while (directive != (c1_using_directive *)0x0);
      if (result != (c1_lookup_result *)0x0) goto LAB_10418ab7;
    }
  }
  else {
    pbVar6 = token_next((c1_token_reader *)&g_token_position);
    if (*pbVar6 == 0x95) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x10;
    }
    pcVar7 = class_lookup_member_set(g_current_scope,pcVar8,name,0x22,0x181);
    if (*pbVar6 == 0x95) {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xffffffef;
    }
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar6);
LAB_104189d2:
    if (pcVar7 != (c1_symbol *)0x0) goto LAB_104189da;
  }
  if ((((g_compile_flags_cc & 0x100000) != 0) && ((pcVar8->kind & 0x1f) == 4)) &&
     ((((pcVar8->detail).cls)->flags3f & 0x80) != 0)) {
    pcVar7 = sym_new_kind1_placeholder(name);
    pcVar7->type = g_type_int;
    pcVar7->flags2 = (~g_paren_level_flags[g_paren_depth] & 1) << 4 | pcVar7->flags2 & 0xef;
    pcVar7 = (c1_symbol *)ovl_make_set_of_two(pcVar8,pcVar7);
    if (pcVar7 != (c1_symbol *)0x0) {
LAB_104189da:
      lookup_qualifier_chain_splice(*(c1_keyed_cell **)pcVar7->type,qualifier->head);
      return (c1_keyed_list *)pcVar7->type;
    }
  }
  if (conv_type == (c1_type *)0x0) {
    pcVar14 = expr_build_member_access_implicit(g_current_scope,name);
    if (pcVar14 == (c1_u8 *)0x0) {
      pbVar6 = (byte *)0x0;
    }
    else {
      pbVar6 = *(byte **)pcVar14;
    }
    if (((pbVar6 != (byte *)0x0) && ((*pbVar6 & 0x1f) == 4)) &&
       ((*(byte *)(*(int *)(pbVar6 + 0x24) + 0x3e) & 1) != 0)) {
      diag_error(0x27,0x53,pbVar6,pcVar8);
      return (c1_keyed_list *)0x0;
    }
    diag_error(0x27,0x49,name,pcVar8);
    if (p4 != '\0') {
      diag_fatal_simple(0x1fb);
    }
  }
  else {
    diag_error(0x27,0x54,conv_type,pcVar8);
  }
  return (c1_keyed_list *)0x0;
}

