void __cdecl import_emit_vtable_method(void *typeinfo,void *funcdesc,wchar_t *class_name)

{
  bool bVar1;
  char *pcVar2;
  bool bVar3;
  wchar_t **ppwVar4;
  long err;
  int iVar5;
  int iVar6;
  int *piVar7;
  wchar_t *pwVar8;
  uint uVar9;
  short *psVar10;
  int iVar11;
  char *pcVar12;
  void *pvVar13;
  c1_typedesc *typedesc;
  bool bVar14;
  int iStack_28;
  char *pcStack_20;
  uint local_1c;
  char *pcStack_18;
  int iStack_14;
  char *pcStack_10;
  void *pvStack_c;
  wchar_t **local_8;
  int iStack_4;
  
  bVar14 = *(short *)((int)funcdesc + 0x24) == 0x19;
  iVar11 = (int)*(short *)((int)funcdesc + 0x18);
  import_text_puts(g_import_member_raw_methods,"    virtual ");
  import_write_typedesc
            (g_import_member_raw_methods,(void *)((int)funcdesc + 0x20),typeinfo,(wchar_t *)0x0,0);
  if (*(int *)((int)funcdesc + 0x14) != 0) {
    import_text_putc(g_import_member_raw_methods,0x20);
    import_write_calling_convention(g_import_member_raw_methods,*(int *)((int)funcdesc + 0x14));
  }
  uVar9 = iVar11 + 1;
  ppwVar4 = __2_YAPAXI_Z(uVar9 * 4);
  local_1c = 0;
  local_8 = ppwVar4;
  err = (**(code **)(*(int *)typeinfo + 0x1c))(typeinfo,*(long *)funcdesc,ppwVar4,uVar9,&local_1c);
  if (err < 0) {
    diag_fatal_file(err,0x54,0x166,g_import_file_as_written);
  }
  ppwVar4 = import_rename_param_names(ppwVar4,uVar9,local_1c);
  iVar5 = *(int *)((int)funcdesc + 0x10);
  bVar3 = false;
  if (iVar5 == 2) {
    pcStack_18 = g_import_high_get_prefix;
    pcStack_20 = g_import_raw_get_prefix;
LAB_1049dc94:
    bVar1 = bVar3;
    pcStack_10 = "";
  }
  else {
    if (iVar5 == 4) {
      pcStack_18 = g_import_high_put_prefix;
      pcStack_20 = g_import_raw_put_prefix;
      goto LAB_1049dc94;
    }
    if (iVar5 == 8) {
      pcStack_18 = g_import_high_putref_prefix;
      pcStack_20 = g_import_raw_putref_prefix;
      goto LAB_1049dc94;
    }
    bVar1 = true;
    pcStack_18 = g_import_high_method_prefix;
    if (((bVar14) || (g_import_raw_interfaces_only != 0)) ||
       ((pcStack_20 = g_import_high_method_prefix, g_import_raw_method_prefix_given != 0 &&
        (g_import_high_method_prefix_given != 0)))) {
      pcStack_20 = g_import_raw_method_prefix;
    }
    iVar5 = wcscmp(class_name,*ppwVar4);
    pcStack_10 = "_";
    bVar3 = true;
    if (iVar5 != 0) goto LAB_1049dc94;
  }
  iVar6 = 1;
  iStack_28 = 0;
  iVar5 = iStack_28;
  if (0 < iVar11) {
    psVar10 = (short *)(*(int *)((int)funcdesc + 8) + 4);
    do {
      if (((*(byte *)(psVar10 + 4) & 10) == 10) && (iVar5 = iVar6, *psVar10 == 0x1a)) break;
      iVar6 = iVar6 + 1;
      psVar10 = psVar10 + 8;
      iVar5 = iStack_28;
    } while (iVar6 <= iVar11);
  }
  iStack_28 = iVar5;
  import_text_printf(g_import_member_raw_methods," %s%s%S (",pcStack_20,pcStack_10,*ppwVar4);
  pvVar13 = *(void **)((int)funcdesc + 8);
  iVar6 = (int)*(short *)((int)funcdesc + 0x1a);
  iStack_14 = 0;
  piVar7 = (int *)(iVar11 * 0x10 + -0x10 + (int)pvVar13);
  iVar5 = iVar11;
  if (0 < iVar11) {
    do {
      if ((iVar5 != iStack_28) &&
         (((*(ushort *)(piVar7 + 3) & 10) != 0 ||
          (((*(ushort *)(piVar7 + 3) & 4) == 0 &&
           ((((short)piVar7[1] != 0xc &&
             (((short)piVar7[1] != 0x1a || (*(short *)(*piVar7 + 4) != 0xc)))) ||
            (iVar6 = iVar6 + -1, iVar6 < 0)))))))) break;
      iVar5 = iVar5 + -1;
      piVar7 = piVar7 + -4;
      iStack_14 = iStack_14 + 1;
    } while (0 < iVar5);
    iVar5 = 1;
    if (0 < iVar11) {
      do {
        import_text_puts(g_import_member_raw_methods,"\n        ");
        iVar6 = 0;
        pwVar8 = import_param_name(iVar5,ppwVar4);
        import_write_typedesc(g_import_member_raw_methods,pvVar13,typeinfo,pwVar8,iVar6);
        if ((iStack_28 == 0) && (iVar11 - iStack_14 < iVar5)) {
          if ((*(byte *)((int)pvVar13 + 0xc) & 4) == 0) {
            pcVar12 = "&";
            if (*(short *)((int)pvVar13 + 4) != 0x1a) {
              pcVar12 = "";
            }
            import_text_printf(g_import_member_raw_methods," = %svtMissing",pcVar12);
          }
          else {
            import_text_puts(g_import_member_raw_methods," = 0");
          }
        }
        if (iVar5 < iVar11) {
          import_text_putc(g_import_member_raw_methods,0x2c);
        }
        iVar5 = iVar5 + 1;
        pvVar13 = (void *)((int)pvVar13 + 0x10);
      } while (iVar5 <= iVar11);
    }
  }
  import_text_puts(g_import_member_raw_methods," ) = 0;\n");
  if ((!bVar14) || (g_import_raw_interfaces_only != 0)) goto LAB_1049e21e;
  import_text_puts(g_import_member_wrappers,"    ");
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
  if (iStack_28 == 0) {
    pcVar12 = "HRESULT";
    if (!bVar1) {
      pcVar12 = "void";
    }
    import_text_puts(g_import_member_wrappers,pcVar12);
    import_text_puts(g_import_member_implementations,pcVar12);
    if (g_import_function_mapping != 0) {
      import_text_puts(g_import_mapping,pcVar12);
    }
  }
  else {
    pvVar13 = *(void **)(iStack_28 * 0x10 + -0x10 + *(int *)((int)funcdesc + 8));
    pvStack_c = pvVar13;
    iVar5 = import_write_wrapper_type(g_import_member_wrappers,pvVar13,typeinfo,0);
    iStack_4 = import_write_wrapper_type
                         (g_import_member_implementations,pvVar13,typeinfo,
                          CONCAT31((int3)((uint)iVar5 >> 8),g_import_function_mapping));
    if (g_import_function_mapping != 0) {
      import_write_wrapper_type(g_import_mapping,pvVar13,typeinfo,0);
    }
  }
  pcVar2 = pcStack_10;
  pcVar12 = pcStack_18;
  import_text_printf(g_import_member_wrappers," %s%s%S (",pcStack_18,pcStack_10,*ppwVar4);
  import_text_putc(g_import_member_implementations,0x20);
  if ((g_import_function_mapping != 0) &&
     (import_text_printf(g_import_mapping," %S::%s%s%S (",class_name,pcVar12,pcVar2,*ppwVar4),
     g_import_no_namespace == 0)) {
    import_text_printf(g_import_member_implementations,"%S::",g_import_namespace);
  }
  import_text_printf(g_import_member_implementations,"%S::%s%s%S (",class_name,pcVar12,pcVar2,
                     *ppwVar4);
  if ((int)(uint)(iStack_28 != 0) < iVar11) {
    typedesc = *(c1_typedesc **)((int)funcdesc + 8);
    iVar5 = 1;
    bVar14 = false;
    if (0 < iVar11) {
      do {
        if (iVar5 != iStack_28) {
          if (bVar14) {
            import_text_putc(g_import_member_wrappers,0x2c);
            import_text_putc(g_import_member_implementations,0x2c);
            if (g_import_function_mapping != 0) {
              import_text_putc(g_import_mapping,0x2c);
            }
          }
          bVar14 = true;
          import_text_puts(g_import_member_wrappers,"\n        ");
          import_text_putc(g_import_member_implementations,0x20);
          pwVar8 = import_param_name(iVar5,ppwVar4);
          import_write_wrapper_param_type(g_import_member_wrappers,typedesc,typeinfo,pwVar8);
          import_write_wrapper_param_type(g_import_member_implementations,typedesc,typeinfo,pwVar8);
          if (g_import_function_mapping != 0) {
            import_text_putc(g_import_mapping,0x20);
            import_write_wrapper_param_type(g_import_mapping,typedesc,typeinfo,pwVar8);
          }
          if (iVar11 - iStack_14 < iVar5) {
            if ((typedesc[1].vt & 4) == 0) {
              pcVar12 = "&";
              if (typedesc->vt != 0x1a) {
                pcVar12 = "";
              }
              import_text_printf(g_import_member_wrappers," = %svtMissing",pcVar12);
            }
            else {
              import_text_puts(g_import_member_wrappers," = 0");
            }
          }
        }
        iVar5 = iVar5 + 1;
        typedesc = typedesc + 2;
      } while (iVar5 <= iVar11);
    }
  }
  import_text_puts(g_import_member_wrappers," );\n");
  import_text_puts(g_import_member_implementations," ) ");
  if (g_import_function_mapping != 0) {
    import_text_puts(g_import_mapping," );\n");
  }
  import_text_puts(g_import_member_implementations,"{\n");
  if (iStack_28 != 0) {
    import_text_puts(g_import_member_implementations,"    ");
    pvVar13 = pvStack_c;
    import_write_typedesc(g_import_member_implementations,pvStack_c,typeinfo,L"_result",0);
    import_text_puts(g_import_member_implementations,";\n");
    if (*(short *)((int)pvVar13 + 4) == 0xc) {
      import_text_puts(g_import_member_implementations,"    VariantInit(&_result);\n");
    }
  }
  import_text_printf(g_import_member_implementations,"    HRESULT _hr = %s%s%S(",pcStack_20,
                     pcStack_10,*ppwVar4);
  iVar5 = 1;
  if (0 < iVar11) {
    do {
      if (iVar5 == iStack_28) {
        import_text_puts(g_import_member_implementations,"&_result");
      }
      else {
        pwVar8 = import_param_name(iVar5,ppwVar4);
        import_text_printf(g_import_member_implementations,"%S",pwVar8);
      }
      if (iVar5 < iVar11) {
        import_text_puts(g_import_member_implementations,", ");
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= iVar11);
  }
  import_text_puts(g_import_member_implementations,");\n");
  import_text_puts(g_import_member_implementations,
                   "    if (FAILED(_hr)) _com_issue_errorex(_hr, this, __uuidof(this));\n");
  if (iStack_28 == 0) {
    if (bVar1) {
      pcVar12 = "    return _hr;\n";
      goto LAB_1049e203;
    }
  }
  else {
    import_text_puts(g_import_member_implementations,"    return ");
    if (iStack_4 == 0) {
      pcVar12 = "_result;\n";
    }
    else {
      if ((iStack_4 < 1) || (3 < iStack_4)) goto LAB_1049e20e;
      import_write_wrapper_type(g_import_member_implementations,pvStack_c,typeinfo,0);
      pcVar12 = "(_result, false);\n";
    }
LAB_1049e203:
    import_text_puts(g_import_member_implementations,pcVar12);
  }
LAB_1049e20e:
  import_text_puts(g_import_member_implementations,"}\n");
LAB_1049e21e:
  __3_YAXPAX_Z(ppwVar4);
  ppwVar4 = local_8;
  uVar9 = local_1c - 1;
  if (local_1c == 0) {
    local_1c = uVar9;
    __3_YAXPAX_Z(local_8);
    return;
  }
  do {
    local_1c = uVar9;
    SysFreeString(ppwVar4[uVar9]);
    uVar9 = local_1c - 1;
  } while (local_1c != 0);
  local_1c = uVar9;
  __3_YAXPAX_Z(ppwVar4);
  return;
}

