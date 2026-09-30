# QA register and test plan

Scope: intentionally incomplete baseline `6894c1d`, revised with AI assistance.

| Issue | Root cause | Correction | Verification |
|---|---|---|---|
| #1 High | No output direction configured | pinMode plus explicit LOW | Source inspection; board test pending |
| #2 Medium | delay blocks the loop | millis elapsed-time polling | Source inspection; timing test pending |
| #3 Low | Repeated literals | LED_BUILTIN and named interval | Source inspection |
| #4 Medium | Missing reproducibility and test criteria | README, QA and plan | Document review |

The issue descriptions propose host-mock checks. These have not been executed; verification in this revision consists of source review and the separately recorded CI compile result.

## Five Whys for issue #1
1. Why may the LED fail to behave as intended? Its pin is not driven as a normal output.
2. Why? setup does not call pinMode with OUTPUT.
3. Why? The baseline only contains the repeated switching sequence.
4. Why was the omission not prevented? Initialization was absent from the review checklist.
5. Why was the checklist incomplete? No explicit startup acceptance criterion existed.

Prevent recurrence: require pin configuration and a known initial output in the checklist.

## Acceptance tests
| ID | Procedure | Expected result | Execution |
|---|---|---|---|
| T1 | Compile for arduino:avr:uno | Successful compile | GitHub Actions records result |
| T2 | Inspect setup and loop | OUTPUT, LOW, one interval, no delay | Passed source review |
| T3 | Reset board; observe 10 full cycles | Initially OFF; ON/OFF about 1 s each, total about 20 s | Not run: hardware required |
| T4 | Probe output transitions | Each interval 1000 ms +/- 50 ms for this classroom test | Not run: hardware required |
| T5 | Inject timer values around wrap in a test harness | 0xFFFFFF00 to 0x000002E7: 999 ms; to 0x000002E8: 1000 ms | Arithmetic review only; no execution |

Issue closure refers to source/documentation correction, not proof of physical operation. A separate open issue tracks hardware acceptance and independent review.
