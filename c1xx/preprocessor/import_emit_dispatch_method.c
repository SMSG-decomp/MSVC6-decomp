bool __cdecl import_emit_dispatch_method(void *typeinfo,void *funcdesc,wchar_t *class_name)

{
  byte bVar1;
  ushort uVar2;
  long err;
  wchar_t **ppwVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  wchar_t *pwVar7;
  char *pcVar8;
  char *result_prefix;
  uint uVar9;
  ushort *puVar10;
  c1_typedesc *pcVar11;
  int iVar12;
  int iVar13;
  void *typedesc;
  c1_import_param_writer_fn write_param;
  c1_import_param_writer_fn write_param_2;
  bool bVar14;
  bool local_39;
  ushort *puStack_30;
  char *pcStack_2c;
  char *pcStack_24;
  char *pcStack_20;
  uint local_1c;
  char *pcStack_18;
  c1_typedesc *pcStack_14;
  c1_typedesc *pcStack_10;
  wchar_t **local_c;
  int iStack_8;
  int iStack_4;
  
  if ((g_import_raw_interfaces_only != 0) && (g_import_raw_dispinterfaces == 0)) {
    return false;
  }
  iVar12 = (int)*(short *)((int)funcdesc + 0x18);
  local_39 = false;
  uVar9 = iVar12 + 1;
  local_c = __2_YAPAXI_Z(uVar9 * 4);
  local_1c = 0;
  err = (**(code **)(*(int *)typeinfo + 0x1c))(typeinfo,*(long *)funcdesc,local_c,uVar9,&local_1c);
  if (err < 0) {
    diag_fatal_file(err,0x54,0x166,g_import_file_as_written);
  }
  ppwVar3 = import_rename_param_names(local_c,uVar9,local_1c);
  iVar4 = *(int *)((int)funcdesc + 0x10);
  bVar14 = false;
  if (iVar4 == 2) {
    pcStack_2c = g_import_high_get_prefix;
    pcStack_20 = g_import_raw_get_prefix;
    pcStack_18 = "DISPATCH_PROPERTYGET";
  }
  else if (iVar4 == 4) {
    pcStack_2c = g_import_high_put_prefix;
    pcStack_20 = g_import_raw_put_prefix;
    pcStack_18 = "DISPATCH_PROPERTYPUT";
  }
  else if (iVar4 == 8) {
    pcStack_2c = g_import_high_putref_prefix;
    pcStack_20 = g_import_raw_putref_prefix;
    pcStack_18 = "DISPATCH_PROPERTYPUTREF";
  }
  else {
    pcStack_2c = g_import_high_method_prefix;
    bVar14 = true;
    pcStack_20 = g_import_raw_method_prefix;
    pcStack_18 = "DISPATCH_METHOD";
    iVar4 = wcscmp(class_name,*ppwVar3);
    pcStack_24 = "_";
    if (iVar4 == 0) goto LAB_1049e4d2;
  }
  pcStack_24 = "";
LAB_1049e4d2:
  puVar5 = __2_YAPAXI_Z(uVar9 * 2);
  pcStack_14 = (c1_typedesc *)((int)funcdesc + 0x20);
  uVar2 = import_vartype_or_invalid(typeinfo,pcStack_14);
  *puVar5 = uVar2;
  typedesc = *(void **)((int)funcdesc + 8);
  iVar4 = iVar12;
  puVar10 = puVar5;
  if (0 < iVar12) {
    do {
      uVar2 = import_vartype_or_invalid(typeinfo,typedesc);
      puVar10[1] = uVar2;
      typedesc = (void *)((int)typedesc + 0x10);
      iVar4 = iVar4 + -1;
      puVar10 = puVar10 + 1;
    } while (iVar4 != 0);
  }
  if ((*puVar5 == 0xffff) || ((*puVar5 & 0x4000) != 0)) {
    import_text_printf(g_import_member_wrappers,
                       "    // Method \'%s%s%S\' not emitted because of invalid return type: ",
                       pcStack_2c,pcStack_24,*ppwVar3);
    import_write_typedesc_comment(g_import_member_wrappers,pcStack_14,typeinfo);
LAB_1049eed5:
    import_text_putc(g_import_member_wrappers,10);
  }
  else {
    iVar4 = 1;
    puVar10 = puVar5;
    if (0 < iVar12) {
      do {
        if (puVar10[1] == 0xffff) {
          pwVar7 = import_param_name(iVar4,ppwVar3);
          import_text_printf(g_import_member_wrappers,
                             "    // Method \'%s%s%S\' not emitted because argument \'%S\' has invalid type: "
                             ,pcStack_2c,pcStack_24,*ppwVar3,pwVar7);
          import_write_typedesc_comment
                    (g_import_member_wrappers,
                     (c1_typedesc *)(iVar4 * 0x10 + -0x10 + *(int *)((int)funcdesc + 8)),typeinfo);
          goto LAB_1049eed5;
        }
        iVar4 = iVar4 + 1;
        puVar10 = puVar10 + 1;
      } while (iVar4 <= iVar12);
    }
    if (g_import_raw_interfaces_only == 0) {
      import_text_puts(g_import_member_wrappers,"    ");
      if ((*puVar5 == 0) && (bVar14)) {
        import_text_puts(g_import_member_wrappers,"HRESULT");
      }
      else {
        import_write_wrapper_type(g_import_member_wrappers,pcStack_14,typeinfo,0);
      }
      import_text_printf(g_import_member_wrappers," %s%s%S (",pcStack_2c,pcStack_24,*ppwVar3);
    }
    if (g_import_raw_dispinterfaces != 0) {
      import_text_puts(g_import_member_raw_methods,"    HRESULT");
      import_text_printf(g_import_member_raw_methods," %s%s%S (",pcStack_20,pcStack_24,*ppwVar3);
    }
    iVar4 = 0;
    iStack_8 = iVar12 - *(short *)((int)funcdesc + 0x1a);
    if (iStack_8 < iVar12) {
      puVar10 = puVar5 + iVar12;
      iVar6 = iVar12;
      do {
        if ((*puVar10 & 0xbfff) != 0xc) break;
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + -1;
        puVar10 = puVar10 + -1;
      } while (iStack_8 < iVar6);
    }
    if ((0 < iVar12) && (iVar6 = 1, 0 < iVar12)) {
      iVar13 = 0x10;
      puVar10 = puVar5;
      do {
        puStack_30 = puVar10 + 1;
        pwVar7 = import_param_name(iVar6,ppwVar3);
        if (g_import_raw_interfaces_only == 0) {
          import_text_puts(g_import_member_wrappers,"\n        ");
          import_write_wrapper_param_type
                    (g_import_member_wrappers,
                     (c1_typedesc *)(*(int *)((int)funcdesc + 8) + -0x10 + iVar13),typeinfo,pwVar7);
          if (iVar12 - iVar4 < iVar6) {
            pcVar8 = "&";
            if ((*(byte *)((int)puVar10 + 3) & 0x40) == 0) {
              pcVar8 = "";
            }
            import_text_printf(g_import_member_wrappers," = %svtMissing",pcVar8);
          }
          if (iVar6 < iVar12) {
            import_text_putc(g_import_member_wrappers,0x2c);
          }
        }
        if (g_import_raw_dispinterfaces != 0) {
          import_text_puts(g_import_member_raw_methods,"\n        ");
          import_write_raw_param_type
                    (g_import_member_raw_methods,
                     (void *)(*(int *)((int)funcdesc + 8) + -0x10 + iVar13),typeinfo,pwVar7);
          if ((*puVar5 == 0) && (iVar12 - iVar4 < iVar6)) {
            pcVar8 = "&";
            if ((*(byte *)((int)puVar10 + 3) & 0x40) == 0) {
              pcVar8 = "";
            }
            import_text_printf(g_import_member_raw_methods," = %svtMissing",pcVar8);
          }
          if ((iVar6 < iVar12) || (*puVar5 != 0)) {
            import_text_putc(g_import_member_raw_methods,0x2c);
          }
        }
        iVar6 = iVar6 + 1;
        iVar13 = iVar13 + 0x10;
        puVar10 = puStack_30;
      } while (iVar6 <= iVar12);
    }
    if (g_import_raw_interfaces_only == 0) {
      import_text_puts(g_import_member_wrappers," );\n");
    }
    if (g_import_raw_dispinterfaces != 0) {
      if (*puVar5 != 0) {
        import_text_puts(g_import_member_raw_methods,"\n        ");
        import_write_typedesc(g_import_member_raw_methods,pcStack_14,typeinfo,L"* _result",0);
      }
      import_text_puts(g_import_member_raw_methods," );\n");
    }
    puStack_30 = (ushort *)0x0;
    do {
      bVar1 = g_import_raw_interfaces_only;
      if (puStack_30 != (ushort *)0x0) {
        bVar1 = g_import_raw_dispinterfaces == 0;
      }
      if (bVar1 == 0) {
        import_text_putc(g_import_member_implementations,10);
        if (g_import_function_mapping != 0) {
          import_text_printf(g_import_member_implementations,"#pragma implementation_key(%d)\n",
                             g_import_implementation_key);
          import_text_printf(g_import_mapping,"__declspec(implementation_key(%d)) ",
                             g_import_implementation_key);
          g_import_implementation_key = g_import_implementation_key + 1;
        }
        if (g_import_implementation_only == 0) {
          import_text_puts(g_import_member_implementations,"inline ");
        }
        pcVar11 = pcStack_14;
        if ((puStack_30 != (ushort *)0x0) || ((*puVar5 == 0 && (bVar14)))) {
          import_text_puts(g_import_member_implementations,"HRESULT");
          if (g_import_function_mapping != 0) {
            import_text_puts(g_import_mapping,"HRESULT");
          }
        }
        else {
          pcStack_10 = pcStack_14;
          iStack_4 = import_write_wrapper_type
                               (g_import_member_implementations,pcStack_14,typeinfo,
                                g_import_function_mapping);
          if (g_import_function_mapping != 0) {
            import_write_wrapper_type(g_import_mapping,pcVar11,typeinfo,0);
          }
        }
        import_text_putc(g_import_member_implementations,0x20);
        if (g_import_function_mapping != 0) {
          pcVar8 = pcStack_2c;
          if (puStack_30 != (ushort *)0x0) {
            pcVar8 = pcStack_20;
          }
          import_text_printf(g_import_mapping," %S::%s%s%S (",class_name,pcVar8,pcStack_24,*ppwVar3)
          ;
          if (g_import_no_namespace == 0) {
            import_text_printf(g_import_member_implementations,"%S::",g_import_namespace);
          }
        }
        pcVar8 = pcStack_2c;
        if (puStack_30 != (ushort *)0x0) {
          pcVar8 = pcStack_20;
        }
        import_text_printf(g_import_member_implementations,"%S::%s%s%S (",class_name,pcVar8,
                           pcStack_24,*ppwVar3);
        if ((0 < iVar12) && (iVar4 = 1, 0 < iVar12)) {
          iVar6 = 0x10;
          do {
            import_text_putc(g_import_member_implementations,0x20);
            write_param = import_write_wrapper_param_type;
            if (puStack_30 != (ushort *)0x0) {
              write_param = import_write_raw_param_type;
            }
            pwVar7 = import_param_name(iVar4,ppwVar3);
            (*write_param)(g_import_member_implementations,
                           (void *)(*(int *)((int)funcdesc + 8) + -0x10 + iVar6),typeinfo,pwVar7);
            if (g_import_function_mapping != 0) {
              import_text_putc(g_import_mapping,0x20);
              write_param_2 = import_write_wrapper_param_type;
              if (puStack_30 != (ushort *)0x0) {
                write_param_2 = import_write_raw_param_type;
              }
              pwVar7 = import_param_name(iVar4,ppwVar3);
              (*write_param_2)(g_import_mapping,
                               (void *)(*(int *)((int)funcdesc + 8) + -0x10 + iVar6),typeinfo,pwVar7
                              );
            }
            if (((iVar4 < iVar12) || ((puStack_30 != (ushort *)0x0 && (*puVar5 != 0)))) &&
               (import_text_putc(g_import_member_implementations,0x2c),
               g_import_function_mapping != 0)) {
              import_text_putc(g_import_mapping,0x2c);
            }
            iVar4 = iVar4 + 1;
            iVar6 = iVar6 + 0x10;
          } while (iVar4 <= iVar12);
        }
        pcVar11 = pcStack_10;
        if ((puStack_30 != (ushort *)0x0) && (*puVar5 != 0)) {
          import_text_putc(g_import_member_implementations,0x20);
          pcVar11 = pcStack_10;
          import_write_typedesc(g_import_member_implementations,pcStack_10,typeinfo,L"* _presult",0)
          ;
          if (g_import_function_mapping != 0) {
            import_text_putc(g_import_mapping,0x20);
            import_write_typedesc(g_import_mapping,pcVar11,typeinfo,L"* _presult",0);
          }
        }
        import_text_puts(g_import_member_implementations," ) {\n    ");
        if (g_import_function_mapping != 0) {
          import_text_puts(g_import_mapping," );\n");
        }
        if (puStack_30 == (ushort *)0x0) {
          if (*puVar5 == 0) {
            if (bVar14) {
              pcVar8 = "return ";
              goto LAB_1049eb62;
            }
          }
          else {
            import_write_typedesc(g_import_member_implementations,pcVar11,typeinfo,L"_result",0);
            pcVar8 = ";\n    ";
LAB_1049eb62:
            import_text_puts(g_import_member_implementations,pcVar8);
          }
          pcVar8 = "_com_dispatch_method(this, ";
        }
        else {
          pcVar8 = "return _com_dispatch_raw_method(this, ";
        }
        import_text_puts(g_import_member_implementations,pcVar8);
        import_write_dispid(g_import_member_implementations,*(int *)funcdesc);
        import_text_printf(g_import_member_implementations,", %s, ",pcStack_18);
        if (*puVar5 == 0) {
          import_text_puts(g_import_member_implementations,"VT_EMPTY, NULL, ");
        }
        else {
          import_write_vartype_name(g_import_member_implementations,*puVar5);
          result_prefix = "&_";
          if (puStack_30 != (ushort *)0x0) {
            result_prefix = "_p";
          }
          import_text_printf(g_import_member_implementations,", (void*)%sresult, ",result_prefix);
        }
        if (iVar12 < 1) {
          import_text_puts(g_import_member_implementations,"NULL");
        }
        else {
          import_text_puts(g_import_member_implementations,"\n        L\"");
          iVar4 = 1;
          puVar10 = puVar5;
          if (0 < iVar12) {
            do {
              uVar2 = puVar10[1];
              if (iStack_8 < iVar4) {
                uVar2 = uVar2 | 0x800;
              }
              import_text_printf(g_import_member_implementations,"\\x%04x",(uint)uVar2);
              iVar4 = iVar4 + 1;
              puVar10 = puVar10 + 1;
            } while (iVar4 <= iVar12);
          }
          import_text_puts(g_import_member_implementations,"\",");
          iVar4 = 1;
          if (0 < iVar12) {
            iVar6 = 0x10;
            puVar10 = puVar5;
            do {
              puVar10 = puVar10 + 1;
              import_text_putc(g_import_member_implementations,0x20);
              if ((puStack_30 == (ushort *)0x0) &&
                 (bVar1 = import_vt_is_bstr_wrapper(*puVar10), bVar1 != 0)) {
                import_text_putc(g_import_member_implementations,0x28);
                import_write_raw_param_type
                          (g_import_member_implementations,
                           (void *)(*(int *)((int)funcdesc + 8) + -0x10 + iVar6),typeinfo,
                           (wchar_t *)0x0);
                import_text_putc(g_import_member_implementations,0x29);
              }
              bVar1 = import_vt_by_const_ref(*puVar10);
              if (bVar1 != 0) {
                import_text_putc(g_import_member_implementations,0x26);
              }
              pwVar7 = import_param_name(iVar4,ppwVar3);
              import_text_printf(g_import_member_implementations,"%S",pwVar7);
              if (iVar4 < iVar12) {
                import_text_putc(g_import_member_implementations,0x2c);
              }
              iVar4 = iVar4 + 1;
              iVar6 = iVar6 + 0x10;
              pcVar11 = pcStack_10;
            } while (iVar4 <= iVar12);
          }
        }
        import_text_puts(g_import_member_implementations,");\n");
        if ((puStack_30 == (ushort *)0x0) && (*puVar5 != 0)) {
          import_text_puts(g_import_member_implementations,"    return ");
          if (iStack_4 == 0) {
            pcVar8 = "_result;\n";
          }
          else {
            if ((iStack_4 < 1) || (3 < iStack_4)) goto LAB_1049eda7;
            import_write_wrapper_type(g_import_member_implementations,pcVar11,typeinfo,0);
            pcVar8 = "(_result, false);\n";
          }
          import_text_puts(g_import_member_implementations,pcVar8);
        }
LAB_1049eda7:
        import_text_puts(g_import_member_implementations,"}\n");
      }
      puStack_30 = (ushort *)((int)puStack_30 + 1);
    } while ((int)puStack_30 < 2);
    local_39 = true;
  }
  __3_YAXPAX_Z(puVar5);
  __3_YAXPAX_Z(ppwVar3);
  ppwVar3 = local_c;
  uVar9 = local_1c - 1;
  if (local_1c == 0) {
    local_1c = 0xffffffff;
  }
  else {
    do {
      local_1c = uVar9;
      SysFreeString(ppwVar3[uVar9]);
      uVar9 = local_1c - 1;
      bVar14 = local_1c != 0;
      local_1c = uVar9;
    } while (bVar14);
  }
  __3_YAXPAX_Z(ppwVar3);
  return local_39;
}

