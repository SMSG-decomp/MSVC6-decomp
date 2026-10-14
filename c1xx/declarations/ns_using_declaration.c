void __cdecl ns_using_declaration(c1_symbol *sym)

{
  fe_name **ppfVar1;
  c1_symbol *sym_00;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar5;
  c1_symbol *pcVar6;
  int iVar7;
  c1_symbol *pcVar8;
  c1_symbol *other_link_sym;
  c1_symbol *pcVar9;
  c1_symbol *link_sym;
  c1_symbol *link_sym_2;
  fe_name **ppfVar10;
  c1_symbol *pcVar11;
  c1_symbol *pcVar12;
  c1_symbol *apcStack_14 [2];
  c1_symbol *pcStack_c;
  
  pcVar6 = sym;
  if ((sym->kind & 0x1f) != 0x12) {
    diag_error(0x364,sym);
    return;
  }
  sym_00 = (c1_symbol *)(*(int **)sym->type)[2];
  bVar3 = sym_00->kind & 0x1f;
  if (((((bVar3 != 0x10) && (bVar3 != 7)) && (bVar3 != 6)) && ((bVar3 != 10 && (bVar3 != 4)))) &&
     (bVar3 != 5)) {
    if (bVar3 == 3) {
      diag_error(0x375,*(undefined4 *)(**(int **)sym->type + 8),sym_00);
      return;
    }
    diag_error(0x369,0x53,sym_00);
    return;
  }
  ppfVar1 = &sym_00->name;
  result = (*g_current_scope->current->vtbl->lookup)(g_current_scope->current,sym_00->name,1);
  if ((result == (c1_lookup_result *)0x0) ||
     (pcVar5 = lookup_check_ambiguous_symbol(result,'\x01'), pcVar5 == (c1_lookup_entry *)0x0)) {
    apcStack_14[0] = (c1_symbol *)0x0;
  }
  else {
    apcStack_14[0] = pcVar5->sym;
  }
  if (apcStack_14[0] == (c1_symbol *)0x0) {
    bVar3 = sym_00->kind & 0x1f;
    if (((bVar3 != 0x10) && (bVar3 != 7)) && (bVar3 != 6)) {
      pcVar6 = symtable_ice_2(*ppfVar1,sym_00,(c1_symbol *)0x0);
      (*g_current_scope->current->vtbl->insert)(pcVar6);
      return;
    }
    sym = (c1_symbol *)0x0;
    bVar2 = true;
    if (ppfVar1 != (fe_name **)0x0) {
      iVar7 = sym_is_data_or_function_2(sym_00);
      pcVar6 = (c1_symbol *)ppfVar1;
      if (((char)iVar7 == '\0') && ((sym_00->kind & 0x1f) != 0x1a)) {
        pcVar6 = (c1_symbol *)sym_00->type;
      }
      while ((ppfVar1 != (fe_name **)0x0 && (pcVar6 != (c1_symbol *)0x0))) {
        iVar7 = sym_is_data_or_function_2(sym_00);
        if (((char)iVar7 == '\0') && ((sym_00->kind & 0x1f) != 0x1a)) {
          pcVar11 = *(c1_symbol **)&pcVar6->flags4;
        }
        else {
          pcVar11 = (c1_symbol *)0x0;
        }
        if (bVar2) {
          pcVar9 = (c1_symbol *)((int)&pcVar6[-1].tail + 4);
          bVar2 = false;
          pcVar8 = pcVar9;
          if ((*(byte *)((int)&pcVar6[-1].tail + 4) & 0x1f) == 0x1a) {
            pcVar9 = *(c1_symbol **)pcVar6->next;
            pcVar8 = *(c1_symbol **)pcVar6->next;
          }
          sym = symtable_ice_2(pcVar9->name,pcVar8,(c1_symbol *)0x0);
          (*g_current_scope->current->vtbl->insert)(sym);
          pcVar6 = pcVar11;
        }
        else {
          pcVar9 = (c1_symbol *)((int)&pcVar6[-1].tail + 4);
          pcVar8 = pcVar9;
          if ((*(byte *)((int)&pcVar6[-1].tail + 4) & 0x1f) == 0x1a) {
            pcVar9 = *(c1_symbol **)pcVar6->next;
            pcVar8 = *(c1_symbol **)pcVar6->next;
          }
          pcVar6 = symtable_ice_2(pcVar9->name,pcVar8,(c1_symbol *)0x0);
          ns_using_declare_target(&sym,pcVar6);
          pcVar6 = pcVar11;
        }
      }
    }
  }
  else {
    bVar3 = apcStack_14[0]->kind & 0x1f;
    pcVar11 = apcStack_14[0];
    if (bVar3 == 0x1a) {
      pcVar11 = *(c1_symbol **)apcStack_14[0]->type;
    }
    bVar4 = pcVar11->kind & 0x1f;
    sym = pcVar11;
    pcVar9 = apcStack_14[0];
    if (((bVar4 == 0x10) || (bVar4 == 7)) || (bVar4 == 6)) {
      bVar3 = sym_00->kind & 0x1f;
      if (((bVar3 == 0x10) || (bVar3 == 7)) || (bVar3 == 6)) {
        if ((1 < g_block_depth) && (ppfVar10 = &pcVar11->name, ppfVar10 != (fe_name **)0x0)) {
          iVar7 = sym_is_data_or_function_2(pcVar11);
          pcVar6 = (c1_symbol *)ppfVar10;
          if (((char)iVar7 == '\0') && ((pcVar11->kind & 0x1f) != 0x1a)) {
            pcVar6 = (c1_symbol *)pcVar11->type;
          }
          while ((ppfVar10 != (fe_name **)0x0 && (pcVar6 != (c1_symbol *)0x0))) {
            bVar3 = *(byte *)((int)&pcVar6[-1].tail + 4);
            pcVar9 = pcVar6;
            while ((bVar3 & 0x1f) == 0x1a) {
              pcVar9 = *(c1_symbol **)&pcVar9->flags4;
              if (pcVar9 == (c1_symbol *)0x0) goto LAB_104ad336;
              bVar3 = *(byte *)((int)&pcVar9[-1].tail + 4);
            }
            iVar7 = sym_is_data_or_function_2(pcVar11);
            if ((char)iVar7 == '\0') {
              pcVar6 = *(c1_symbol **)&pcVar9->flags4;
            }
            else {
              pcVar6 = (c1_symbol *)0x0;
            }
            pcVar8 = (c1_symbol *)((int)&pcVar9[-1].tail + 4);
            pcVar12 = pcVar8;
            if ((*(byte *)((int)&pcVar9[-1].tail + 4) & 0x1f) == 0x1a) {
              pcVar8 = *(c1_symbol **)pcVar9->next;
              pcVar12 = *(c1_symbol **)pcVar9->next;
            }
            pcVar8 = (c1_symbol *)
                     ovl_find_function_with_type
                               (sym_00,pcVar8->type,1,0,pcVar12,(c1_declarator *)0x0,0);
            if ((pcVar8 != (c1_symbol *)0x0) && (pcVar8 != sym)) {
              link_sym = (c1_symbol *)((int)&pcVar9[-1].tail + 4);
              if ((*(byte *)((int)&pcVar9[-1].tail + 4) & 0x1f) == 0x1a) {
                link_sym = *(c1_symbol **)pcVar9->next;
              }
              diag_error(0x374,pcVar8,link_sym);
              return;
            }
          }
        }
LAB_104ad336:
        pcVar6 = (c1_symbol *)0x0;
        if (((ppfVar1 != (fe_name **)0x0) &&
            (iVar7 = sym_is_data_or_function_2(sym_00), pcVar6 = (c1_symbol *)ppfVar1,
            pcStack_c = (c1_symbol *)ppfVar1, (char)iVar7 == '\0')) &&
           ((sym_00->kind & 0x1f) != 0x1a)) {
          pcVar6 = (c1_symbol *)sym_00->type;
          pcStack_c = (c1_symbol *)sym_00->type;
        }
        do {
          pcVar11 = pcVar6;
          if (ppfVar1 == (fe_name **)0x0) {
            return;
          }
          if (pcVar11 == (c1_symbol *)0x0) {
            return;
          }
          iVar7 = sym_is_data_or_function_2(sym_00);
          pcVar9 = apcStack_14[0];
          if (((char)iVar7 == '\0') && ((sym_00->kind & 0x1f) != 0x1a)) {
            pcStack_c = *(c1_symbol **)&pcVar11->flags4;
          }
          else {
            pcStack_c = (c1_symbol *)0x0;
          }
          ppfVar10 = &apcStack_14[0]->name;
          pcVar8 = (c1_symbol *)0x0;
          if (((ppfVar10 != (fe_name **)0x0) &&
              (iVar7 = sym_is_data_or_function_2(apcStack_14[0]), pcVar8 = (c1_symbol *)ppfVar10,
              (char)iVar7 == '\0')) && ((pcVar9->kind & 0x1f) != 0x1a)) {
            pcVar8 = (c1_symbol *)pcVar9->type;
          }
          do {
            if ((ppfVar10 == (fe_name **)0x0) || (pcVar8 == (c1_symbol *)0x0)) {
              pcVar6 = (c1_symbol *)((int)&pcVar11[-1].tail + 4);
              pcVar9 = pcVar6;
              if ((*(byte *)((int)&pcVar11[-1].tail + 4) & 0x1f) == 0x1a) {
                pcVar6 = *(c1_symbol **)pcVar11->next;
                pcVar9 = *(c1_symbol **)pcVar11->next;
              }
              pcVar6 = symtable_ice_2(pcVar6->name,pcVar9,(c1_symbol *)0x0);
              ns_using_declare_target(apcStack_14,pcVar6);
              pcVar6 = pcStack_c;
              break;
            }
            iVar7 = sym_is_data_or_function_2(pcVar9);
            if (((char)iVar7 == '\0') && ((pcVar9->kind & 0x1f) != 0x1a)) {
              pcVar12 = *(c1_symbol **)&pcVar8->flags4;
            }
            else {
              pcVar12 = (c1_symbol *)0x0;
            }
            link_sym_2 = (c1_symbol *)((int)&pcVar11[-1].tail + 4);
            if ((*(byte *)((int)&pcVar11[-1].tail + 4) & 0x1f) == 0x1a) {
              link_sym_2 = *(c1_symbol **)pcVar11->next;
            }
            other_link_sym = (c1_symbol *)((int)&pcVar8[-1].tail + 4);
            if ((*(byte *)((int)&pcVar8[-1].tail + 4) & 0x1f) == 0x1a) {
              other_link_sym = *(c1_symbol **)pcVar8->next;
            }
            pcVar6 = pcStack_c;
            pcVar8 = pcVar12;
          } while (link_sym_2 != other_link_sym);
        } while( true );
      }
    }
    else {
      pcVar11 = apcStack_14[0];
      if (g_current_scope->current->kind == '\0') {
        while (bVar3 == 0x1a) {
          bVar3 = (*(c1_symbol **)pcVar11->type)->kind & 0x1f;
          pcVar11 = *(c1_symbol **)pcVar11->type;
        }
        bVar3 = sym_00->kind;
        pcVar6 = sym_00;
        while ((bVar3 & 0x1f) == 0x1a) {
          pcVar6 = *(c1_symbol **)pcVar6->type;
          bVar3 = pcVar6->kind;
        }
        pcVar9 = sym_00;
        if (pcVar11 == pcVar6) {
          return;
        }
      }
      else if (bVar3 != 10) {
        diag_error(0x36b,*(undefined4 *)(**(int **)pcVar6->type + 8),sym_00);
        return;
      }
    }
    diag_error(0x36a,pcVar9);
  }
  return;
}

