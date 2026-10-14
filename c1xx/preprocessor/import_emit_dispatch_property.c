void __cdecl
import_emit_dispatch_property(void *typeinfo,void *vardesc,wchar_t *class_name,wchar_t *name)

{
  c1_typedesc *typedesc;
  byte bVar1;
  ushort vt;
  int iVar2;
  char *pcVar3;
  
  if ((g_import_raw_interfaces_only != 0) && (g_import_raw_dispinterfaces == 0)) {
    return;
  }
  typedesc = (c1_typedesc *)((int)vardesc + 0xc);
  vt = import_vartype_or_invalid(typeinfo,typedesc);
  if ((vt == 0xffff) || ((vt & 0x4000) != 0)) {
    import_text_printf(g_import_member_wrappers,
                       "    // Property \'%S\' not emitted because of invalid type: ",name);
    import_write_typedesc_comment(g_import_member_wrappers,typedesc,typeinfo);
    import_text_putc(g_import_member_wrappers,10);
    return;
  }
  iVar2 = wcscmp(class_name,name);
  if (g_import_raw_interfaces_only == 0) {
    import_text_printf(g_import_member_property_data,"    __declspec(property(get=%s%S",
                       g_import_high_get_prefix,name);
    if ((*(byte *)((int)vardesc + 0x1c) & 1) == 0) {
      import_text_printf(g_import_member_property_data,",put=%s%S",g_import_high_put_prefix,name);
    }
    import_text_puts(g_import_member_property_data,"))\n    ");
    import_write_wrapper_type(g_import_member_property_data,typedesc,typeinfo,0);
    pcVar3 = "_";
    if (iVar2 != 0) {
      pcVar3 = "";
    }
    import_text_printf(g_import_member_property_data," %s%S;\n",pcVar3,name);
    if (g_import_raw_interfaces_only == 0) {
      import_text_puts(g_import_member_wrappers,"    ");
      import_write_wrapper_type(g_import_member_wrappers,typedesc,typeinfo,0);
      import_text_printf(g_import_member_wrappers," %s%S ( );\n",g_import_high_get_prefix,name);
    }
  }
  if (g_import_raw_dispinterfaces != 0) {
    import_text_printf(g_import_member_raw_methods,"    HRESULT %s%S ( ",g_import_raw_get_prefix,
                       name);
    import_write_typedesc(g_import_member_raw_methods,typedesc,typeinfo,L"* _presult",0);
    import_text_puts(g_import_member_raw_methods," );\n");
  }
  if ((*(byte *)((int)vardesc + 0x1c) & 1) == 0) {
    if (g_import_raw_interfaces_only == 0) {
      import_text_printf(g_import_member_wrappers,"    void %s%S ( ",g_import_high_put_prefix,name);
      import_write_wrapper_param_type(g_import_member_wrappers,typedesc,typeinfo,L"_val");
      import_text_puts(g_import_member_wrappers," );\n");
    }
    if (g_import_raw_dispinterfaces != 0) {
      import_text_printf(g_import_member_raw_methods,"    HRESULT %s%S ( ",g_import_raw_put_prefix,
                         name);
      import_write_raw_param_type(g_import_member_raw_methods,typedesc,typeinfo,L"_val");
      import_text_puts(g_import_member_raw_methods," );\n");
    }
  }
  if (g_import_raw_interfaces_only == 0) {
    import_text_putc(g_import_member_implementations,10);
    if (g_import_function_mapping != 0) {
      import_text_printf(g_import_member_implementations,"#pragma implementation_key(%d)\n",
                         g_import_implementation_key);
      import_text_printf(g_import_mapping,"__declspec(implementation_key(%d)) ",
                         g_import_implementation_key);
      import_write_wrapper_type(g_import_mapping,typedesc,typeinfo,0);
      import_text_printf(g_import_mapping," %S::%s%S ( );\n",class_name,g_import_high_get_prefix,
                         name);
      g_import_implementation_key = g_import_implementation_key + 1;
    }
    if (g_import_implementation_only == 0) {
      import_text_puts(g_import_member_implementations,"inline ");
    }
    iVar2 = import_write_wrapper_type
                      (g_import_member_implementations,typedesc,typeinfo,g_import_function_mapping);
    import_text_putc(g_import_member_implementations,0x20);
    if ((g_import_function_mapping != 0) && (g_import_no_namespace == 0)) {
      import_text_printf(g_import_member_implementations,"%S::",g_import_namespace);
    }
    import_text_printf(g_import_member_implementations,"%S::%s%S ( ) {\n    ",class_name,
                       g_import_high_get_prefix,name);
    import_write_typedesc(g_import_member_implementations,typedesc,typeinfo,L"_result",0);
    import_text_puts(g_import_member_implementations,";\n    _com_dispatch_propget(this, ");
    import_write_dispid(g_import_member_implementations,*(int *)vardesc);
    import_text_puts(g_import_member_implementations,", ");
    import_write_vartype_name(g_import_member_implementations,vt);
    import_text_puts(g_import_member_implementations,", (void*)&_result);\n    return ");
    if (iVar2 == 0) {
      pcVar3 = "_result;\n}\n";
    }
    else {
      if ((iVar2 < 1) || (3 < iVar2)) goto LAB_1049d472;
      import_write_wrapper_type(g_import_member_implementations,typedesc,typeinfo,0);
      pcVar3 = "(_result, false);\n}\n";
    }
    import_text_puts(g_import_member_implementations,pcVar3);
  }
LAB_1049d472:
  if (g_import_raw_dispinterfaces != 0) {
    import_text_putc(g_import_member_implementations,10);
    if (g_import_function_mapping != 0) {
      import_text_printf(g_import_member_implementations,"#pragma implementation_key(%d)\n",
                         g_import_implementation_key);
      import_text_printf(g_import_mapping,"__declspec(implementation_key(%d)) HRESULT %S::%s%S ( ",
                         g_import_implementation_key,class_name,g_import_raw_get_prefix,name);
      import_write_typedesc(g_import_mapping,typedesc,typeinfo,L"* _presult );\n",0);
      g_import_implementation_key = g_import_implementation_key + 1;
    }
    if (g_import_implementation_only == 0) {
      import_text_puts(g_import_member_implementations,"inline ");
    }
    import_text_puts(g_import_member_implementations,"HRESULT ");
    if ((g_import_function_mapping != 0) && (g_import_no_namespace == 0)) {
      import_text_printf(g_import_member_implementations,"%S::",g_import_namespace);
    }
    import_text_printf(g_import_member_implementations,"%S::%s%S ( ",class_name,
                       g_import_raw_get_prefix,name);
    import_write_typedesc(g_import_member_implementations,typedesc,typeinfo,L"* _presult",0);
    import_text_puts(g_import_member_implementations,
                     " ) {\n    return _com_dispatch_raw_propget(this, ");
    import_write_dispid(g_import_member_implementations,*(int *)vardesc);
    import_text_puts(g_import_member_implementations,", ");
    import_write_vartype_name(g_import_member_implementations,vt);
    import_text_puts(g_import_member_implementations,", (void*)_presult);\n}\n");
  }
  if ((*(byte *)((int)vardesc + 0x1c) & 1) == 0) {
    if (g_import_raw_interfaces_only == 0) {
      import_text_putc(g_import_member_implementations,10);
      if (g_import_function_mapping != 0) {
        import_text_printf(g_import_member_implementations,"#pragma implementation_key(%d)\n",
                           g_import_implementation_key);
        import_text_printf(g_import_mapping,"__declspec(implementation_key(%d)) void %S::%s%S ( ",
                           g_import_implementation_key,class_name,g_import_high_put_prefix,name);
        import_write_wrapper_param_type(g_import_mapping,typedesc,typeinfo,L"_val );\n");
        g_import_implementation_key = g_import_implementation_key + 1;
      }
      if (g_import_implementation_only == 0) {
        import_text_puts(g_import_member_implementations,"inline ");
      }
      import_text_puts(g_import_member_implementations,"void ");
      if ((g_import_function_mapping != 0) && (g_import_no_namespace == 0)) {
        import_text_printf(g_import_member_implementations,"%S::",g_import_namespace);
      }
      import_text_printf(g_import_member_implementations,"%S::%s%S ( ",class_name,
                         g_import_high_put_prefix,name);
      import_write_wrapper_param_type(g_import_member_implementations,typedesc,typeinfo,L"_val");
      import_text_printf(g_import_member_implementations," ) {\n    _com_dispatch_propput(this, ");
      import_write_dispid(g_import_member_implementations,*(int *)vardesc);
      import_text_puts(g_import_member_implementations,", ");
      import_write_vartype_name(g_import_member_implementations,vt);
      import_text_puts(g_import_member_implementations,", ");
      bVar1 = import_vt_is_bstr_wrapper(vt);
      if (bVar1 != 0) {
        import_text_putc(g_import_member_implementations,0x28);
        import_write_raw_param_type
                  (g_import_member_implementations,typedesc,typeinfo,(wchar_t *)0x0);
        import_text_putc(g_import_member_implementations,0x29);
      }
      bVar1 = import_vt_by_const_ref(vt);
      if (bVar1 != 0) {
        import_text_putc(g_import_member_implementations,0x26);
      }
      import_text_puts(g_import_member_implementations,"_val);\n}\n");
    }
    if (g_import_raw_dispinterfaces != 0) {
      import_text_putc(g_import_member_implementations,10);
      if (g_import_function_mapping != 0) {
        import_text_printf(g_import_member_implementations,"#pragma implementation_key(%d)\n",
                           g_import_implementation_key);
        import_text_printf(g_import_mapping,"__declspec(implementation_key(%d)) HRESULT %S::%s%S ( "
                           ,g_import_implementation_key,class_name,g_import_raw_put_prefix,name);
        import_write_raw_param_type(g_import_mapping,typedesc,typeinfo,L"_val );\n");
        g_import_implementation_key = g_import_implementation_key + 1;
      }
      if (g_import_implementation_only == 0) {
        import_text_puts(g_import_member_implementations,"inline ");
      }
      import_text_puts(g_import_member_implementations,"HRESULT ");
      if ((g_import_function_mapping != 0) && (g_import_no_namespace == 0)) {
        import_text_printf(g_import_member_implementations,"%S::",g_import_namespace);
      }
      import_text_printf(g_import_member_implementations,"%S::%s%S ( ",class_name,
                         g_import_raw_put_prefix,name);
      import_write_raw_param_type(g_import_member_implementations,typedesc,typeinfo,L"_val");
      import_text_printf(g_import_member_implementations,
                         " ) {\n    return _com_dispatch_raw_propput(this, ");
      import_write_dispid(g_import_member_implementations,*(int *)vardesc);
      import_text_puts(g_import_member_implementations,", ");
      import_write_vartype_name(g_import_member_implementations,vt);
      import_text_puts(g_import_member_implementations,", ");
      bVar1 = import_vt_by_const_ref(vt);
      if (bVar1 != 0) {
        import_text_putc(g_import_member_implementations,0x26);
      }
      import_text_puts(g_import_member_implementations,"_val);\n}\n");
      return;
    }
  }
  return;
}

