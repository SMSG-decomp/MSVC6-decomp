void __cdecl import_emit_vtable_gap(int n)

{
  import_text_printf(g_import_member_raw_methods,
                     "    virtual HRESULT _VtblGapPlaceholder%d( ) { return E_NOTIMPL; }\n",n);
  return;
}

