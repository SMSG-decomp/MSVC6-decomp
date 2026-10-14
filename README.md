# MSVC6-decomp

A research decompilation of the Microsoft Visual C++ 6.0 compiler, organized to help people understand how it turns source into machine code. It grew out of the work on [SMSG-decomp](https://github.com/SMSG-decomp/SMSG-decomp), where understanding compiler decisions helped explain differences between rebuilt game functions and the originals.

**This project does not build.** The C files are Ghidra decompiler output with recovered names and types, arranged by subsystem for reading. There is no build system, working replacement compiler, or claim of binary equivalence with Microsoft's compiler. The purpose is to make the compiler's internals easier to study when reconstructing games built with VC6.

## Reading the tree

The compiler is split into a driver, two front ends, and a shared back end:

| Directory | Component | What to look for |
| --- | --- | --- |
| [cl](cl/) | `CL.EXE` | Command-line options, files, and orchestration of compiler passes. |
| [c1](c1/) | `C1.DLL` | C preprocessing, parsing, types, and intermediate-language emission. |
| [c1xx](c1xx/) | `C1XX.DLL` | C++ parsing, overload resolution, templates, class layout, and intermediate-language emission. |
| [c2](c2/) | `C2.DLL` | Optimization, inlining, register allocation, instruction selection, and object emission. |

Each component has a header containing recovered types and one C file per decompiled function. Subdirectories group related functions. Names and types are interpretations of the binary and can be incomplete or wrong; generated casts, temporary variables, and unresolved globals remain in the output.

Some useful starting points:

- [CL's driver](cl/driver/cl_main.c) and [C2's function-compilation driver](c2/driver/compile_functions.c) for the overall flow.
- [C++ class layout](c1xx/classes/class_layout_vptrs.c) and the surrounding [class routines](c1xx/classes/) for virtual tables, inheritance, and synthesized members.
- [C1's IL emission](c1/il/) and [C2's IL reader](c2/ilread/) for the boundary between front end and back end.
- [Inlining](c2/inline/), [global optimization](c2/globopt/), [register allocation](c2/regalloc/), and [stack frames](c2/frame/) for code-generation decisions.
- [Object and debug-information emission](c2/emit/) for the compiler's output structures.

## Using it for a game decompilation

Start with a specific difference in a game's generated code: a register choice, stack offset, inlining decision, class layout, or ordering of emitted data. Find the corresponding compiler subsystem, then reduce the game code to a small experiment with the original compiler. Compare its assembly or object output with the behavior suggested by the decompilation.

Treat the original compiler's behavior and disassembly as the evidence. A plausible recovered function name or C expression is a hypothesis to check. Compiler version, flags, translation-unit context, and runtime dependencies can affect the result.

The companion **MSVC6-tooling** repository contains Rust analysis tools, compiler models, and small source/expectation probes for this kind of investigation. Its tools build separately; this decompilation remains a reading reference.

## Credits and license

Visual C++ 6.0 is the work of Microsoft Corporation and its compiler team. All credit for the compiler goes to them.

- [Ghidra](https://github.com/NationalSecurityAgency/ghidra) produced the decompiler output.
- [microsoft/microsoft-pdb](https://github.com/microsoft/microsoft-pdb) supplied the names of PDB interfaces in the front-end headers; see [THIRD-PARTY-NOTICES](THIRD-PARTY-NOTICES).
- [homm3-decomp](https://github.com/sushi-shi/homm3-decomp) provided prior research into C2 and the shim used to trace it.

See [LICENSE](LICENSE), [COPYING](COPYING), and [THIRD-PARTY-NOTICES](THIRD-PARTY-NOTICES) for license terms and attribution.
