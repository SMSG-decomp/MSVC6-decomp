void __cdecl pass_unload(passrec *p)

{
  if (p->module != (HMODULE)0x0) {
    FreeLibrary(p->module);
    p->module = (void *)0x0;
    p->invoke = (cl_invoke_pass)0x0;
    p->abort = (cl_abort_pass)0x0;
  }
  return;
}

