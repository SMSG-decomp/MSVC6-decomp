void __cdecl cl_exit(int code)

{
  il_files_delete(0);
  exit(code);
}

