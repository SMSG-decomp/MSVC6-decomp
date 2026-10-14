c1_u8 * __thiscall decl_bind_block_declaration(c1_scope_stack *stack,c1_declarator *d)

{
  fe_name *name;
  c1_u8 *pcVar1;
  byte bVar2;
  char cVar3;
  c1_sym_link *formal;
  c1xx_hash_scope *scope;
  c1_lookup_result *result;
  c1_symbol *pcVar4;
  c1_symbol *pcVar5;
  uint uVar6;
  c1_symbol *value;
  
  name = d->name;
  if ((g_block_depth == '\x02') && (stack->current->kind != '\x01')) {
    if (g_function_parameter_scope == (c1_sym_list *)0x0) {
      formal = (c1_sym_link *)0x0;
    }
    else {
      formal = g_function_parameter_scope->head;
    }
    for (; formal != (c1_sym_link *)0x0; formal = formal->next) {
      if (formal->name == name) {
        diag_error(0x52,name);
        pcVar1 = g_arenas[5].cur;
        g_arenas[5].cur = g_arenas[5].cur + 0xc;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (pcVar1 == (c1_u8 *)0x0) {
          return (c1_u8 *)0x0;
        }
        pcVar4 = sym_new_from_declarator(d,0xffffffff);
        *(c1_symbol **)pcVar1 = pcVar4;
        pcVar1[4] = '\0';
        pcVar1[5] = '\0';
        pcVar1[6] = '\0';
        pcVar1[7] = '\0';
        pcVar1[8] = '\0';
        pcVar1[9] = '\0';
        pcVar1[10] = '\0';
        pcVar1[0xb] = '\0';
        return pcVar1;
      }
      if (formal == (c1_sym_link *)0x0) break;
    }
  }
  if ((d->spec[0] & 7) == 1) {
    scope = scope_enclosing_namespace(stack,'\0');
    result = (*scope->vtbl->lookup)(scope,name,0);
    if (result == (c1_lookup_result *)0x0) {
      pcVar4 = (c1_symbol *)0x0;
    }
    else {
      pcVar4 = (c1_symbol *)lookup_unique_symbol(result);
    }
    pcVar4 = expr_resolve_overload_set_member(pcVar4,(c1_symbol *)0x0);
    if (((pcVar4 != (c1_symbol *)0x0) && (bVar2 = pcVar4->kind & 0x1f, bVar2 != 4)) &&
       ((bVar2 == 0 || (((0xe < bVar2 || (bVar2 == 5)) || ((pcVar4->storage & 7) != 7)))))) {
      if ((((bVar2 == 0x10) || (bVar2 == 7)) ||
          ((bVar2 == 6 || (((bVar2 == 0x11 || (bVar2 == 8)) || (bVar2 == 0x1b)))))) ||
         ((bVar2 == 0x1a &&
          (((((bVar2 = **(byte **)pcVar4->type & 0x1f, bVar2 == 0x10 || (bVar2 == 7)) ||
             (bVar2 == 6)) || ((bVar2 == 0x11 || (bVar2 == 8)))) || (bVar2 == 0x1b)))))) {
        g_compile_flags_c8 = g_compile_flags_c8 | 0x2000;
        pcVar5 = d->sym;
        if (pcVar5 == (c1_symbol *)0x0) {
          pcVar5 = sym_new_from_declarator(d,5);
        }
        pcVar4 = (c1_symbol *)ovl_find_function_with_type(pcVar4,d->type,1,0,pcVar5,d,0);
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffdfff;
        if (pcVar4 == (c1_symbol *)0x0) {
          return (c1_u8 *)0x0;
        }
      }
      g_compile_flags_c8 = g_compile_flags_c8 | 0x2000;
      cVar3 = decl_check_redeclaration(d,pcVar4);
      if (cVar3 == '\0') {
        pcVar5 = sym_new_from_declarator(d,0xffffffff);
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffdfff;
        pcVar5->entity = (pcVar5->entity ^ pcVar4->entity) & 0xffffff ^ pcVar5->entity;
        if (g_c9il_mode == '\0') {
          if ((pcVar4->key_ref & 0xfffffff8) == 0) {
            uVar6 = il_symbol_key_assign(pcVar4);
          }
          else {
            uVar6 = pcVar4->key_ref >> 3;
          }
        }
        else {
          uVar6 = pcVar4->entity & 0xffffff;
        }
        pcVar5->key_ref = uVar6 * 8 | pcVar5->key_ref & 7;
        pcVar5->flags5 = (pcVar4->flags5 ^ pcVar5->flags5) & 4 ^ pcVar5->flags5;
        if ((pcVar4->flags23 & 1) != 0) {
          value = sym_segment_record(pcVar4);
          if (value == (c1_symbol *)0x0) {
            pcVar5->flags23 = pcVar5->flags23 & 0xfe;
          }
          else {
            sym_set_segment(pcVar5,value);
          }
        }
        pcVar5->flags5 = (pcVar4->flags5 ^ pcVar5->flags5) & 1 ^ pcVar5->flags5;
        (*stack->current->vtbl->insert)(pcVar5);
        if ((pcVar4->kind & 0x1f) == 6) {
          pcVar5->storage = pcVar5->storage & 0xf8 ^ 1;
          pcVar5->kind = pcVar5->kind & 0xe6 | 6;
          (pcVar5->detail).halves.lo = (pcVar4->detail).halves.lo;
          (pcVar5->detail).halves.hi = (pcVar4->detail).halves.hi;
        }
        sym_mark_referenced(pcVar4);
        pcVar5->flags2 = pcVar5->flags2 | 8;
        pcVar4->flags2 = pcVar4->flags2 & 0xf7;
        pcVar1 = g_arenas[5].cur;
        g_arenas[5].cur = g_arenas[5].cur + 0xc;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (pcVar1 != (c1_u8 *)0x0) {
          *(c1_symbol **)pcVar1 = pcVar4;
          pcVar1[4] = '\0';
          pcVar1[5] = '\0';
          pcVar1[6] = '\0';
          pcVar1[7] = '\0';
          pcVar1[8] = '\0';
          pcVar1[9] = '\0';
          pcVar1[10] = '\0';
          pcVar1[0xb] = '\0';
          return pcVar1;
        }
      }
      else {
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffdfff;
      }
    }
  }
  return (c1_u8 *)0x0;
}

