void __cdecl pp_import_parse_attributes(c1_vector *attributes)

{
  byte bVar1;
  byte *pbVar2;
  void *pvVar3;
  c1_vector *pcVar4;
  bool bVar5;
  c1_u8 *item;
  int iVar6;
  byte *pbVar7;
  wchar_t *pwVar8;
  void *pvVar9;
  int iVar10;
  byte *pbVar11;
  short sVar12;
  void **attr_row;
  bool bVar13;
  short local_8;
  c1_import_attribute *attr_entry;
  
  g_import_no_namespace = 0;
  g_import_raw_interfaces_only = 0;
  g_import_raw_dispinterfaces = 0;
  g_import_namespace = (wchar_t *)0x0;
  g_import_excludes = vector_new(0,5);
  g_import_includes = vector_new(0,5);
  g_import_injected_statements = vector_new(0,5);
  g_import_renames = vector_new(0,5);
  g_import_no_auto_exclude = 0;
  g_import_named_guids = 0;
  g_import_no_implementation = 0;
  g_import_implementation_only = 0;
  g_import_raw_method_prefix_given = 0;
  g_import_high_method_prefix_given = 0;
  g_import_raw_method_prefix = "raw_";
  g_import_high_method_prefix = "";
  g_import_raw_get_prefix = "get_";
  g_import_raw_put_prefix = "put_";
  g_import_raw_putref_prefix = "putref_";
  g_import_high_get_prefix = "Get";
  g_import_high_put_prefix = "Put";
  g_import_high_putref_prefix = "PutRef";
  g_import_raw_native_types = 0;
  g_import_smartptr_suffix = "Ptr";
  g_import_variant_type = "_variant_t";
  g_import_bstr_type = "_bstr_t";
  g_import_no_dual_interfaces = 0;
  g_import_dual_interfaces = 0;
  bVar5 = false;
  g_import_function_mapping = 0;
  g_import_function_mapping_default = 1;
  local_8 = 0;
switchD_104a2203_default:
  do {
    item = g_arenas[5].cur;
    iVar10 = 0;
    if ((attributes == (c1_vector *)0x0) ||
       (iVar6 = (int)local_8, (int)(uint)attributes->count <= iVar6)) {
      if ((g_import_dual_interfaces != 0) && (g_import_no_dual_interfaces != 0)) {
        diag_warning(1,0xbb,"dual_interfaces","no_dual_interfaces");
        g_import_dual_interfaces = 0;
        g_import_no_dual_interfaces = 0;
      }
      if ((g_import_function_mapping != 0) && (bVar5)) {
        diag_warning(1,0xbb,"function_mapping","no_function_mapping");
        g_import_function_mapping_default = 1;
        g_import_function_mapping = 0;
      }
      if ((g_import_raw_interfaces_only != 0) && (g_import_raw_dispinterfaces == 0)) {
        g_import_no_implementation = 1;
      }
      if ((g_import_renames == (c1_vector *)0x0) || (g_import_renames->count == 0)) {
        g_import_renames = (c1_vector *)0x0;
      }
      if ((g_import_excludes == (c1_vector *)0x0) || (g_import_excludes->count == 0)) {
        g_import_excludes = (c1_vector *)0x0;
      }
      if ((g_import_includes == (c1_vector *)0x0) || (g_import_includes->count == 0)) {
        g_import_includes = (c1_vector *)0x0;
      }
      return;
    }
    local_8 = local_8 + 1;
    attr_row = &g_import_attribute_table;
    attr_entry = attributes->data[iVar6];
    pbVar2 = (byte *)attr_entry->name;
    do {
      pbVar7 = *attr_row;
      pbVar11 = pbVar2;
      do {
        bVar1 = *pbVar7;
        bVar13 = bVar1 < *pbVar11;
        if (bVar1 != *pbVar11) {
LAB_104a21b2:
          iVar6 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          goto LAB_104a2193;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar7[1];
        bVar13 = bVar1 < pbVar11[1];
        if (bVar1 != pbVar11[1]) goto LAB_104a21b2;
        pbVar7 = pbVar7 + 2;
        pbVar11 = pbVar11 + 2;
      } while (bVar1 != 0);
      iVar6 = 0;
LAB_104a2193:
      if (iVar6 == 0) {
        if (iVar10 != 0x15) {
          pvVar3 = attr_row[1];
          if (-1 < (int)pvVar3) {
            if (attr_entry->args == (c1_vector *)0x0) {
              pvVar9 = (void *)0x0;
            }
            else {
              pvVar9 = (void *)(uint)attr_entry->args->count;
            }
            if (pvVar9 != pvVar3) {
              diag_warning(1,0xba,pbVar2,pvVar3);
              goto switchD_104a2203_default;
            }
          }
          pcVar4 = attr_entry->args;
          switch(iVar10) {
          case 0:
            g_import_no_namespace = 1;
            break;
          case 1:
            g_import_raw_interfaces_only = 1;
            if (g_import_raw_method_prefix_given == 0) {
              g_import_raw_method_prefix = "";
            }
            break;
          case 2:
            g_import_raw_dispinterfaces = 1;
            break;
          case 3:
            g_arenas[5].cur = g_arenas[5].cur + 8;
            if (g_arenas[5].end < g_arenas[5].cur) {
              arena_grow(g_arenas + 5);
            }
            pwVar8 = multibyte_to_wide_arena(*pcVar4->data);
            *(wchar_t **)item = pwVar8;
            pwVar8 = multibyte_to_wide_arena(pcVar4->data[1]);
            *(wchar_t **)(item + 4) = pwVar8;
            vector_push(g_import_renames,item);
            break;
          case 4:
            g_import_namespace = multibyte_to_wide_arena(*pcVar4->data);
            break;
          case 5:
            for (sVar12 = 0;
                (pcVar4 != (c1_vector *)0x0 && ((int)sVar12 < (int)(uint)pcVar4->count));
                sVar12 = sVar12 + 1) {
              pwVar8 = multibyte_to_wide_arena(pcVar4->data[sVar12]);
              vector_push(g_import_excludes,pwVar8);
            }
            break;
          case 6:
            for (sVar12 = 0;
                (pcVar4 != (c1_vector *)0x0 && ((int)sVar12 < (int)(uint)pcVar4->count));
                sVar12 = sVar12 + 1) {
              pwVar8 = multibyte_to_wide_arena(pcVar4->data[sVar12]);
              vector_push(g_import_includes,pwVar8);
            }
            break;
          case 7:
            g_import_no_auto_exclude = 1;
            break;
          case 8:
            vector_push(g_import_injected_statements,*pcVar4->data);
            break;
          case 9:
            g_import_named_guids = 1;
            break;
          case 10:
            g_import_no_implementation = 1;
            break;
          case 0xb:
            g_import_implementation_only = 1;
            break;
          case 0xc:
            g_import_raw_native_types = 1;
            g_import_variant_type = "VARIANT";
            g_import_bstr_type = "BSTR";
            break;
          case 0xd:
            g_import_no_dual_interfaces = 1;
            break;
          case 0xe:
            g_import_dual_interfaces = 1;
            break;
          case 0xf:
            g_import_function_mapping_default = 0;
            g_import_function_mapping = 1;
            break;
          case 0x10:
            g_import_function_mapping_default = 0;
            bVar5 = true;
            break;
          case 0x11:
            g_import_raw_method_prefix = *pcVar4->data;
            g_import_raw_method_prefix_given = 1;
            break;
          case 0x12:
            g_import_high_method_prefix = *pcVar4->data;
            g_import_high_method_prefix_given = 1;
            break;
          case 0x13:
            g_import_raw_get_prefix = *pcVar4->data;
            g_import_raw_put_prefix = pcVar4->data[1];
            g_import_raw_putref_prefix = pcVar4->data[2];
            break;
          case 0x14:
            g_import_high_get_prefix = *pcVar4->data;
            g_import_high_put_prefix = pcVar4->data[1];
            g_import_high_putref_prefix = pcVar4->data[2];
          }
          goto switchD_104a2203_default;
        }
        break;
      }
      attr_row = attr_row + 2;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 0x15);
    diag_warning(1,0xb9,pbVar2);
  } while( true );
}

