#include <bangtal>
using namespace bangtal;

int main()
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	ScenePtr scene = Scene::create("방", "Images/방.png");

	// 시작 및 종료 버튼, 아기, 말풍선과 지시어 등 기본 환경 설정
	auto ObjectX = 700, ObjectY = 440;
	ObjectPtr bubble = Object::create("Images/말풍선.png", scene, ObjectX-100, ObjectY-140);
	bubble->setScale(0.4f);
	ObjectPtr chicken = Object::create("Images/치킨.png", scene, ObjectX, ObjectY, true);
	chicken->setScale(0.2f);
	ObjectPtr dog = Object::create("Images/강아지.png", scene, ObjectX, ObjectY, false);
	dog->setScale(0.4f);
	ObjectPtr rice = Object::create("Images/밥.png", scene, ObjectX, ObjectY, false);
	rice->setScale(0.4f);
	ObjectPtr love = Object::create("Images/사랑.png", scene, ObjectX, ObjectY, false);
	love->setScale(0.4f);
	ObjectPtr spoon = Object::create("Images/숟가락.png", scene, ObjectX, ObjectY, false);
	spoon->setScale(0.4f);

	ObjectPtr baby = Object::create("Images/아기.png", scene, 370, 140);

	auto startButton = Object::create("Images/start.png", scene, 590, 70);
	auto endButton = Object::create("Images/end.png", scene, 590, 20);

	//게임 시작 버튼을 누르면 지시어가 뜨고 타이머가 실행된다.
	auto timer1 = Timer::create(0.4f);
	auto timer2 = Timer::create(0.4f);
	auto timer3 = Timer::create(0.4f);
	auto timer4 = Timer::create(0.4f);
	auto timer5 = Timer::create(0.4f);
	showTimer(timer1);
	showTimer(timer2);

	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		startButton->hide();
		endButton->hide();

		showMessage("'치킨'이라고 말해보자! *알맞은 그림이 뜰 때 아무 키나 누르세요");
		timer1->start();

		return true;
		});

	timer1->setOnTimerCallback([&](TimerPtr timer) -> bool {
		chicken->hide();
		dog->show();

		chicken->drop();
		dog->pick();

		timer2->start();

		return true;
		});

	timer2->setOnTimerCallback([&](TimerPtr timer) -> bool {
		dog->hide();
		rice->show();

		dog->drop();
		rice->pick();

		timer3->start();

		return true;
		});

	timer3->setOnTimerCallback([&](TimerPtr timer) -> bool {
		rice->hide();
		love->show();

		rice->drop();
		love->pick();

		timer4->start();

		return true;
		});

	timer4->setOnTimerCallback([&](TimerPtr timer) -> bool {
		love->hide();
		spoon->show();

		love->drop();
		spoon->pick();

		timer5->start();

		return true;
		});

	timer5->setOnTimerCallback([&](TimerPtr timer) -> bool {
		spoon->hide();
		chicken->show();

		spoon->drop();
		chicken->pick();

		timer1->start();

		return true;
		});

	baby->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (chicken->isHanded()) {
			showMessage("성공!");
		}
		else {
			showMessage("실패!");
		}

		return true;
		});

	showMessage("'강아지'라고 말해보자!");

	showMessage("'밥'이라고 말해보자!");

	showMessage("'사랑'이라고 말해보자!");


	showMessage("'숟가락'이라고 말해보자!");


	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();

		return true;
		});


	startGame(scene);

	return 0;
}